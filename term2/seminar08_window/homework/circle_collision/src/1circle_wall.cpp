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

const int windowWidth = 800;
const int windowHeight = 600;

// Определяет насколько затухает скорость после соударения (1.0 = упругое отталкивание)
float collisionDecay = 0.97f;
// Включить выталкивание из стенки (если оно выключено, то шарик может начать застрявать в стенке)
bool enablePushingOut = true;
// Число кадров в секунду
int framelimit = 60;
bool enableInfo = true;

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
        if (position.x > windowWidth - radius)
        {
            // Выталкиваем из стенки
            if (enablePushingOut)
                position.x = windowWidth - radius;
            // Задаём скорость
            velocity.x *= -1;
            // Затухание скорости при соударении
            velocity *= collisionDecay;
        }
        else if (position.x < radius)
        {
            if (enablePushingOut)
                position.x = radius;
            velocity.x *= -1;
            velocity *= collisionDecay;
        } 
        if (position.y > windowHeight - radius)
        {
            if (enablePushingOut)
                position.y = windowHeight - radius;
            velocity.y *= -1;
            velocity *= collisionDecay;
        }
        else if (position.y < radius)
        {
            if (enablePushingOut)
                position.y = radius;
            velocity.y *= -1;
            velocity *= collisionDecay;
        } 
    }

    void draw(sf::RenderWindow& window)
    {
        sf::CircleShape ballShape;
        ballShape.setFillColor(sf::Color::White);
        ballShape.setRadius(radius);
        ballShape.setOrigin(radius, radius);    
        ballShape.setPosition(position);
        window.draw(ballShape);
    }

};

std::string getInfo(sf::RenderWindow& window)
{
    return "Info:\n"
    "h           --  hide/show this info\n"
    "left click  --  set ball's velocity\n"
    "right click --  set ball's position\n"
    "Space       --  turn on/off pushing out (currently - " 
    + std::string(enablePushingOut ? "ON" : "OFF") + ")\n"
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
        enablePushingOut = !enablePushingOut;
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
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Circle-wall collision detection", sf::Style::Default, settings);
    window.setFramerateLimit(framelimit);

    Ball ball = {{200, 300}, {700, 0}, 28};


    sf::Font font;
    if (!font.loadFromFile("consolas.ttf"))
    {
        std::cout << "Error, no font named consolas.ttf" << std::endl;
        std::exit(1);
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
                handleKeyPresses(window, event);

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2f cursorPosition = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    ball.velocity = (cursorPosition - ball.position) * 10.0f;
                }
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    ball.position = cursorPosition;
                    ball.velocity = sf::Vector2f(0, 0);
                }
            }
        }
        
        info.setString(getInfo(window));

        window.clear(sf::Color::Black);

        ball.update(1.0f / framelimit);
        ball.draw(window);

        if (enableInfo)
            window.draw(info);

        window.display();
    }

    return 0;
}