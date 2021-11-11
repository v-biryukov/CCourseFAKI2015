#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>


const int window_width = 1024;
const int window_height = 768;


bool enable_ball_pushing_out = true;
bool enable_info = true;

float collision_decay = 0.99f;
int framelimit = 60;

// Перегрузим оператор, для удобного вычисления скалярного произведения
// Операторы + - = += -= уже перегружены в SFML по умолчанию
float operator*(const sf::Vector2f& first, const sf::Vector2f& second)
{
    return first.x*second.x + first.y*second.y;
}

struct Ball
{
    sf::Vector2f position;
    sf::Vector2f velocity; 
    float radius;
    float mass;

    Ball(sf::Vector2f position, sf::Vector2f velocity, float radius, float mass):
            position(position), velocity(velocity), radius(radius), mass(mass)
    {
    }

    Ball()
    {
    }

    void draw(sf::RenderWindow& window)
    {
        sf::CircleShape ball_shape; // тут можно написать поэффективней и не создавать экземпляр каждый раз
        ball_shape.setFillColor(sf::Color::White);
        ball_shape.setRadius(radius);
        ball_shape.setOrigin(radius, radius);    
        ball_shape.setPosition(position);
        int color_intensity = 400 - (int)mass;
        if (color_intensity < 120) color_intensity = 120;
        if (color_intensity > 255) color_intensity = 255;
        ball_shape.setFillColor(sf::Color(255 - mass, 255 - mass/2, 255 - mass/2));
        window.draw(ball_shape);
    }

    void update(float dt)
    {
        position += velocity * dt;
        if (position.x > window_width - radius)
        {
            // Выталкиваем из стенки
            position.x = window_width - radius;
            // Задаём скорость
            velocity.x *= -1;
            // Затухание скорости при соударении
            velocity *= collision_decay;
        }
        else if (position.x < radius)
        {
            position.x = radius;
            velocity.x *= -1;
            velocity *= collision_decay;
        } 
        if (position.y > window_height - radius)
        {
            position.y = window_height - radius;
            velocity.y *= -1;
            velocity *= collision_decay;
        }
        else if (position.y < radius)
        {
            position.y = radius;
            velocity.y *= -1;
            velocity *= collision_decay;
        } 
    }
};


void handle_collision(Ball& a, Ball& b)
{
    sf::Vector2f d = a.position - b.position;
    if (d*d < (a.radius + b.radius)*(a.radius + b.radius))
    {
        // Переходим в систему отсчёта, связанную с центром масс
        sf::Vector2f center_mass_velocity = (a.mass*a.velocity + b.mass*b.velocity) / (a.mass + b.mass);
        a.velocity -= center_mass_velocity;
        b.velocity -= center_mass_velocity;
        // В этой системе нужно просто обратить составляющую скорости, параллельную вектору d
        // (velocity*d)/(d*d)*d - это вектор проекции скорости на вектор d
        a.velocity -= 2*(a.velocity*d)/(d*d)*d;
        b.velocity -= 2*(b.velocity*d)/(d*d)*d;

        // Выталкивание (если его отключить, то шары могут слипаться)
        if (enable_ball_pushing_out)
        {
            float dnorm = sqrtf(d*d);
            float av = fabs(a.velocity*d);
            float bv = fabs(b.velocity*d);
            float intersect_depth = (a.radius + b.radius - dnorm);
            a.position += av/(av+bv)*intersect_depth/dnorm*d;
            b.position -= bv/(av+bv)*intersect_depth/dnorm*d;
        }

        // Затухание скорости при соударении
        a.velocity *= collision_decay;
        b.velocity *= collision_decay;

        // Переходим обратно в глобальную систему отсчёта
        a.velocity += center_mass_velocity;
        b.velocity += center_mass_velocity;
    }
}

Ball create_random_ball(float x, float y, float max_speed)
{
    Ball random_ball;
    random_ball.radius = 10 + rand() % 40;
    random_ball.mass = 30 + rand() % 220;
    random_ball.position.x = x;
    random_ball.position.y = y;
    random_ball.velocity.x = (rand() % (2*(int)max_speed + 1)) - max_speed;
    random_ball.velocity.y = (rand() % (2*(int)max_speed + 1)) - max_speed;
    return random_ball;
}


std::string get_info(sf::RenderWindow& window)
{
    return "Info:\n"
    "h           --  hide/show this info\n"
    "left click  --  create ball\n"
    "right click --  create high speed ball\n"
    "Space       --  turn on/off ball pushing out (currently - " 
        + std::string(enable_ball_pushing_out ? "ON" : "OFF") + ")\n"
    "W/S         --  change framelimit (currently " + std::to_string(framelimit) + ")\n"
    "Q/A         --  change collision decay (currently " + std::to_string(collision_decay) + ")\n";
}


void handle_key_presses(sf::RenderWindow& window, const sf::Event& event)
{
    if (event.key.code == sf::Keyboard::H)
    {
        enable_info = !enable_info;
    }
    if (event.key.code == sf::Keyboard::Space)
    {
        enable_ball_pushing_out = !enable_ball_pushing_out;
    }
    if (event.key.code == sf::Keyboard::W)
    {
        framelimit += 1;
        window.setFramerateLimit(framelimit);
    }
    if (event.key.code == sf::Keyboard::S)
    {
        framelimit -= 1;
        if (framelimit < 1)
            framelimit = 1;
        window.setFramerateLimit(framelimit);
    }
    if (event.key.code == sf::Keyboard::Q)
    {
        collision_decay += 0.01;
        if (collision_decay > 1)
            collision_decay = 1;
    }
    if (event.key.code == sf::Keyboard::A)
    {
        collision_decay -= 0.01;
        if (collision_decay < 0)
            collision_decay = 0;
    }
}


int main()
{
    srand(time(0));
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Circle circle elastic bounce", sf::Style::Default, settings);
    window.setFramerateLimit(framelimit);

    sf::Font font;
    if (!font.loadFromFile("../consolas.ttf"))
    {
        if (!font.loadFromFile("consolas.ttf"))
            std::cout << "Error, no font named consolas.ttf" << std::endl;
    }
    sf::Text info;
    info.setFont(font);
    info.setCharacterSize(20);



    std::vector<Ball> balls;
    // Легкий шарик:
    balls.push_back({{200, 300}, {300, 0}, 20, 70});
    // Очень тяжёлый шарик весом 5000:
    balls.push_back({{600, 340}, {-300, 0}, 50, 5000});

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                handle_key_presses(window, event);
            }  
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                    balls.push_back(create_random_ball(event.mouseButton.x, event.mouseButton.y, 300));
                if (event.mouseButton.button == sf::Mouse::Right)
                    balls.push_back(create_random_ball(event.mouseButton.x, event.mouseButton.y, 1500));
            }
        }
        

        // Перемещаем все шарики
        for (int i = 0; i < balls.size(); ++i)
            balls[i].update(1.0f / framelimit);

        // Обрабатываем столкновения
        for (int i = 0; i < balls.size(); ++i)
            for (int j = i+1; j < balls.size(); ++j)
                handle_collision(balls[i], balls[j]);
        

        window.clear(sf::Color::Black);
        // Рисуем все шарики
        for (int i = 0; i < balls.size(); ++i)
        {
            balls[i].draw(window);
        }

        // Рисуем информацию
        info.setString(get_info(window));
        if (enable_info)
            window.draw(info);

        window.display();
    }

    return 0;
}