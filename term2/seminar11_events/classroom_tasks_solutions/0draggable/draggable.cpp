#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Draggable");
    window.setFramerateLimit(60);

    sf::RectangleShape rect({200, 150});
    rect.setPosition({300, 300});
    rect.setFillColor(sf::Color(95, 164, 143));

    sf::Vector2f offset;
    bool isDragged = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();


            sf::Vector2f mousePosition = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                if (rect.getGlobalBounds().contains(mousePosition))
                {
                    isDragged = true;
                    offset = mousePosition - rect.getPosition();
                }
            }


            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                isDragged = false;
            }


            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
                if (isDragged)
                {
                    rect.setPosition(mousePosition - offset);
                }
            }
        }
        
        window.clear(sf::Color::Black);
        window.draw(rect);
        window.display();
    }
}