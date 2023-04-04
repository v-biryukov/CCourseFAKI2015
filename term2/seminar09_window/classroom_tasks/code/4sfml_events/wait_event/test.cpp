#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

// Программа, которая рисует движущийся круг

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Moving Circle");
    sf::CircleShape circle(20);
    circle.setPosition(sf::Vector2f{20, 20});

    while (true) 
    {
        sf::Event event;
        if (window.waitEvent(event)) 
        {
        }
        
        circle.move({1, 0.5});

        window.clear(sf::Color::Black);
        window.draw(circle);

        window.display();

        sf::sleep(sf::milliseconds(10));
    }
}