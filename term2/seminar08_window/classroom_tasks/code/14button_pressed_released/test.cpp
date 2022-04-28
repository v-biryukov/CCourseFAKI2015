#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

// Программа, которая обрабатывает нажатия и отпускания кнопок мыши
// При нажатии на ЛКМ кружок меняет свой цвет на красный
// При отпускании ПКМ кружок меняет свой цвет на зелёный

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Key Pressed");
    window.setFramerateLimit(60);

    sf::CircleShape circle(150);
    circle.setPosition({200, 200});


    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "Left mouse button is pressed" << std::endl;
                    circle.setFillColor({200, 100, 100});
                }
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    std::cout << "Right mouse button is released!" << std::endl;
                    circle.setFillColor({100, 200, 100});
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }
}