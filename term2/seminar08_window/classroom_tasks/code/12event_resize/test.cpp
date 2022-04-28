#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

// Программа, которая обрабатывает событие изменения размеров окна

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Moving Circle");
    window.setFramerateLimit(60);

    sf::CircleShape circle(150);
    circle.setPosition({200, 200});

    while (true) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::Resized)
            {
                std::cout << "Resized!" << std::endl;
                std::cout << event.size.width << " " << event.size.height << std::endl;
                std::cout << window.getSize().x << " " << window.getSize().y << std::endl;
            }
        }

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }
}