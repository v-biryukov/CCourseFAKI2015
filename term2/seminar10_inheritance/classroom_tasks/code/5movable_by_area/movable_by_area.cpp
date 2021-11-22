#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "movable_by_area.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "MovableByArea Class!");
    window.setFramerateLimit(60);

    MovableByArea a {window, {200, 200, 200, 200}, {240, 240, 170, 100}};

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            a.handleEvent(event);

        }

        window.clear(sf::Color::Black);
        a.draw();
        window.display();
    }

    return 0;
}