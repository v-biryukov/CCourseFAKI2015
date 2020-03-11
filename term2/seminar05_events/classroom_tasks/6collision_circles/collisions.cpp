#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

struct Ball
{
    float radius;
    float mass;
    sf::Vector2f position;
    sf::Vector2f velocity;

    Ball(float radius, float mass, sf::Vector2f pos, sf::Vector2f vel) : 
        radius(radius), mass(mass), position(pos), velocity(vel)
    {
    }

    void draw(sf::RenderWindow& window)
    {
        sf::CircleShape circle(radius);
        circle.setOrigin(radius, radius);
        circle.setPosition(position);
        window.draw(circle);
    }

    void move(float dt)
    {
        position += velocity * dt;
    }

    void check_borders(sf::Vector2u sizes)
    {
        if (position.x < radius)
            velocity.x *= -1;
        if (position.x > sizes.x - radius)
            velocity.x *= -1;

        if (position.y < radius)
            velocity.y *= -1;
        if (position.y > sizes.y - radius)
            velocity.y *= -1;
    }
};


int main()
{
    srand(time(0));
    // Создаём экземпляр класса окно
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Key handling", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    const float dt = 1.0 / 60;

    Ball a = {20, 5,  {100, 300}, { 200, 0}};
    Ball b = {40, 20, {450, 340}, {-100, 0}};
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
			
        }

        // Проверяем, зажата ли кнопка мыши - каждый кадр
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
        }
        window.clear(sf::Color::Black);

        a.move(dt);
        b.move(dt);
        a.check_borders(window.getSize());
        b.check_borders(window.getSize());

        // рисуем круг на скрытом холсте
        a.draw(window);
        b.draw(window);

        // отображаем содержимое скрытого холста на экран
        window.display();
    }

    return 0;
}