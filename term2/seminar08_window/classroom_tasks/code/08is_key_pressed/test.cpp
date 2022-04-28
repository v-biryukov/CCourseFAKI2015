#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

// Программа, которая рисует движущийся круг когда нажата клавиша Пробел

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Moving Circle when Space is pressed");
    window.setFramerateLimit(60);

    sf::CircleShape circle(20);

    while (true) {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) 
            circle.move({2, 2});

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }
}