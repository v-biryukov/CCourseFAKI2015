#include <iostream>
#include <cstdio>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "button.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Button Class");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("consolas.ttf")) 
    {
        std::cout << "Can't load button font" << std::endl;
        std::exit(1);
    }

    Button button(window, {300, 250, 160, 60}, font, 20, "Hello world!");

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            bool isButtonActivated = button.handleEvent(event);
            if (isButtonActivated)
                std::cout << "Button pressed!" << std::endl;
        }

        window.clear(sf::Color::Black);
        button.draw();
        window.display();
    }

    return 0;
}