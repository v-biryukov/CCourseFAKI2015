/* 
    Программа, которая обрабатывает нажатия и отпускания клавиш.
    При нажатии на левую кнопку мыши кружок меняет свой цвет на красный.
    При отпускании левой кнопки мыши кружок меняет свой цвет на зелёный.
*/

#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Mouse Button Pressed or Relesed");
    window.setFramerateLimit(60);

    sf::CircleShape circle(100);
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
                    std::cout << "LMB is pressed" << std::endl;
                    circle.setFillColor({200, 100, 100});
                }
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "LMB is released!" << std::endl;
                    circle.setFillColor({100, 200, 100});
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }
}