#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

// Перегрузим оператор, для удобного вычисления скалярного произведения
// Операторы + - = += -= уже перегружены в SFML по умолчанию
float operator*(const sf::Vector2f& first, const sf::Vector2f& second)
{
    return first.x*second.x + first.y*second.y;
}

const int window_width = 800;
const int window_height = 600;

// Определяет насколько затухает скорость после соударения (1.0 = упругое отталкивание)
float collision_decay = 0.97f;
// Включить выталкивание из стенки (если оно выключено, то шарик может начать застрявать в стенке)
bool enable_pushing_out = false;
// Число кадров в секунду
int framelimit = 60;

bool enable_info = true;

struct Ball
{
    sf::Vector2f position;
    sf::Vector2f velocity; 
    float radius;

    Ball(sf::Vector2f position, sf::Vector2f velocity, float radius):
            position(position), velocity(velocity), radius(radius)
    {
    }

    void update(float dt)
    {
        position += velocity * dt;
        if (position.x > window_width - radius)
        {
            // Выталкиваем из стенки
            if (enable_pushing_out)
                position.x = window_width - radius;
            // Задаём скорость
            velocity.x *= -1;
            // Затухание скорости при соударении
            velocity *= collision_decay;
        }
        else if (position.x < radius)
        {
            if (enable_pushing_out)
                position.x = radius;
            velocity.x *= -1;
            velocity *= collision_decay;
        } 
        if (position.y > window_height - radius)
        {
            if (enable_pushing_out)
                position.y = window_height - radius;
            velocity.y *= -1;
            velocity *= collision_decay;
        }
        else if (position.y < radius)
        {
            if (enable_pushing_out)
                position.y = radius;
            velocity.y *= -1;
            velocity *= collision_decay;
        } 
    }

    void draw(sf::RenderWindow& window)
    {
        sf::CircleShape ball_shape; // тут можно написать поэффективней и не создавать экземпляр каждый раз
        ball_shape.setFillColor(sf::Color::White);
        ball_shape.setRadius(radius);
        ball_shape.setOrigin(radius, radius);    
        ball_shape.setPosition(position);
        window.draw(ball_shape);
    }

};

std::string get_info(sf::RenderWindow& window)
{
    return "Info:\n"
    "h           --  hide/show this info\n"
    "left click  --  set ball's velocity\n"
    "right click --  set ball's position\n"
    "Space       --  turn on/off pushing out (currently - " 
    + std::string(enable_pushing_out ? "ON" : "OFF") + ")\n"
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
        enable_pushing_out = !enable_pushing_out;
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
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Circle-wall collision detection", sf::Style::Default, settings);
    window.setFramerateLimit(framelimit);

    Ball ball = {{200, 300}, {700, 0}, 28};


    sf::Font font;
    if (!font.loadFromFile("../consolas.ttf"))
    {
        if (!font.loadFromFile("consolas.ttf"))
            std::cout << "Error, no font named consolas.ttf" << std::endl;
    }
    sf::Text info;
    info.setFont(font);
    info.setCharacterSize(20);

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
                sf::Vector2f cursor_position = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    ball.velocity = (cursor_position - ball.position) * 10.0f;
                }
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    ball.position = cursor_position;
                    ball.velocity = sf::Vector2f(0, 0);
                }
            }
        }
        
        info.setString(get_info(window));

        window.clear(sf::Color::Black);

        ball.update(1.0f / framelimit);
        ball.draw(window);

        if (enable_info)
            window.draw(info);

        window.display();
    }

    return 0;
}