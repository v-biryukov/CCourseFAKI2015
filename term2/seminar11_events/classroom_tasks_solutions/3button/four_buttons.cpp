#include <iostream>
#include <cstdio>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "button.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Buttons to move a circle!");
    window.setFramerateLimit(60);

    sf::CircleShape circle(10);
    circle.setOrigin({10, 10});
    circle.setPosition({400, 300});

    sf::Font font;
    if (!font.loadFromFile("consolas.ttf")) 
    {
        std::cout << "Can't load button font" << std::endl;
        std::exit(1);
    }

    std::vector buttons
    {
        Button{window, {200, 300, 60, 60}, font, 20, "Left"},
        Button{window, {300, 300, 60, 60}, font, 20, "Right"},
        Button{window, {250, 200, 60, 60}, font, 20, "Up"},
        Button{window, {250, 400, 60, 60}, font, 20, "Down"}
    };

    const float step = 20;
    std::vector directions
    {
        sf::Vector2f{-step, 0.0f},
        sf::Vector2f{+step, 0.0f},
        sf::Vector2f{0.0f, -step},
        sf::Vector2f{0.0f, +step},
    };


    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();

            for (int i = 0; i < 4; ++i) 
            {
                if (buttons[i].handleEvent(event))
                    circle.move(directions[i]);
            }
        }

        window.clear(sf::Color::Black);
        for (auto& button : buttons)
            button.draw();

        window.draw(circle);
        window.display();
    }
}