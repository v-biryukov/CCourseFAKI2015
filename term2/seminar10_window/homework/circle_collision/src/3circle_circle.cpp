#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

const int windowWidth = 1024;
const int windowHeight = 768;

bool enableBallPushingOut = true;
bool enableInfo = true;

float collisionDecay = 0.99f;
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

    void draw(sf::RenderWindow& window) const
    {
        sf::CircleShape ballShape;
        ballShape.setFillColor(sf::Color::White);
        ballShape.setRadius(radius);
        ballShape.setOrigin(radius, radius);    
        ballShape.setPosition(position);
        int colorIntensity = 400 - static_cast<int>(mass);
        if (colorIntensity < 120) 
            colorIntensity = 120;
        if (colorIntensity > 255) 
            colorIntensity = 255;
        ballShape.setFillColor(sf::Color(colorIntensity / 1.5, colorIntensity / 1.5, colorIntensity));
        window.draw(ballShape);
    }

    void update(float dt)
    {
        position += velocity * dt;
        if (position.x > windowWidth - radius)
        {
            // Выталкиваем из стенки
            position.x = windowWidth - radius;
            // Задаём скорость
            velocity.x *= -1;
            // Затухание скорости при соударении
            velocity *= collisionDecay;
        }
        else if (position.x < radius)
        {
            position.x = radius;
            velocity.x *= -1;
            velocity *= collisionDecay;
        } 
        if (position.y > windowHeight - radius)
        {
            position.y = windowHeight - radius;
            velocity.y *= -1;
            velocity *= collisionDecay;
        }
        else if (position.y < radius)
        {
            position.y = radius;
            velocity.y *= -1;
            velocity *= collisionDecay;
        } 
    }
};


void handleCollision(Ball& a, Ball& b)
{
    sf::Vector2f d = a.position - b.position;
    if (d * d < (a.radius + b.radius) * (a.radius + b.radius))
    {
        // Переходим в систему отсчёта, связанную с центром масс
        sf::Vector2f centerMassVelocity = (a.mass * a.velocity + b.mass * b.velocity) / (a.mass + b.mass);
        a.velocity -= centerMassVelocity;
        b.velocity -= centerMassVelocity;
        // В этой системе нужно просто обратить составляющую скорости, параллельную вектору d
        // (velocity*d)/(d*d)*d - это вектор проекции скорости на вектор d
        a.velocity -= 2 * (a.velocity * d) / (d * d) * d;
        b.velocity -= 2 * (b.velocity * d) / (d * d) * d;

        // Выталкивание (если его отключить, то шары могут слипаться)
        if (enableBallPushingOut)
        {
            float dnorm = sqrt(d*d);
            float av = fabs(a.velocity*d);
            float bv = fabs(b.velocity*d);
            float intersectDepth = (a.radius + b.radius - dnorm);
            a.position += av / (av + bv) * intersectDepth / dnorm * d;
            b.position -= bv / (av + bv) * intersectDepth / dnorm * d;
        }

        // Затухание скорости при соударении
        a.velocity *= collisionDecay;
        b.velocity *= collisionDecay;

        // Переходим обратно в глобальную систему отсчёта
        a.velocity += centerMassVelocity;
        b.velocity += centerMassVelocity;
    }
}

Ball createRandomBall(sf::Vector2f position, float maxSpeed)
{
    Ball randomBall;
    randomBall.radius = 10 + std::rand() % 40;
    randomBall.mass = 30 + std::rand() % 220;
    randomBall.position = position;
    randomBall.velocity.x = (std::rand() % (2 * static_cast<int>(maxSpeed) + 1)) - maxSpeed;
    randomBall.velocity.y = (std::rand() % (2 * static_cast<int>(maxSpeed) + 1)) - maxSpeed;
    return randomBall;
}


std::string getInfo(sf::RenderWindow& window)
{
    return "Info:\n"
    "h           --  hide/show this info\n"
    "left click  --  create ball\n"
    "right click --  create high speed ball\n"
    "Space       --  turn on/off ball pushing out (currently - " 
        + std::string(enableBallPushingOut ? "ON" : "OFF") + ")\n"
    "W/S         --  change framelimit (currently " + std::to_string(framelimit) + ")\n"
    "Q/A         --  change collision decay (currently " + std::to_string(collisionDecay) + ")\n";
}


void handleKeyPresses(sf::RenderWindow& window, const sf::Event& event)
{
    if (event.key.code == sf::Keyboard::H)
    {
        enableInfo = !enableInfo;
    }
    else if (event.key.code == sf::Keyboard::Space)
    {
        enableBallPushingOut = !enableBallPushingOut;
    }
    else if (event.key.code == sf::Keyboard::W)
    {
        framelimit += 1;
        window.setFramerateLimit(framelimit);
    }
    else if (event.key.code == sf::Keyboard::S)
    {
        framelimit -= 1;
        if (framelimit < 1)
            framelimit = 1;
        window.setFramerateLimit(framelimit);
    }
    else if (event.key.code == sf::Keyboard::Q)
    {
        collisionDecay += 0.01;
        if (collisionDecay > 1)
            collisionDecay = 1;
    }
    else if (event.key.code == sf::Keyboard::A)
    {
        collisionDecay -= 0.01;
        if (collisionDecay < 0)
            collisionDecay = 0;
    }
}

int main()
{
    std::srand(std::time(0));
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Circle circle elastic bounce", sf::Style::Default, settings);
    window.setFramerateLimit(framelimit);

    sf::Font font;
    if (!font.loadFromFile("consolas.ttf"))
    {
        std::cout << "Error, no font named consolas.ttf" << std::endl;
        std::exit(1);
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
                handleKeyPresses(window, event);
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
                if (event.mouseButton.button == sf::Mouse::Left)
                    balls.push_back(createRandomBall(mousePosition, 300));
                if (event.mouseButton.button == sf::Mouse::Right)
                    balls.push_back(createRandomBall(mousePosition, 1500));
            }
        }
        
        // Перемещаем все шарики
        for (auto& ball : balls)
            ball.update(1.0f / framelimit);

        // Обрабатываем столкновения
        for (auto& a : balls) 
        {
            for (auto& b : balls)
            {
                if (&a != &b)
                    handleCollision(a, b);
            }
        }
        
        window.clear(sf::Color::Black);

        // Рисуем все шарики
        for (auto& b : balls)
            b.draw(window);

        // Рисуем информацию
        info.setString(getInfo(window));
        if (enableInfo)
            window.draw(info);

        window.display();
    }

    return 0;
}