#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

// Программа, которая рисует движущийся круг
// Круг движется с одной скоростью, независимо от fps

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Moving Circle");
    sf::setFramerateLimit(60);

    sf::CircleShape circle(20);
    circle.setPosition(sf::Vector2f{20, 20});
    sf::Vector2f circleVelocity {25, 40};

    sf::Clock clock;

    while (true) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
        }
        float dt = clock.restart().asSeconds();

        circle.move(circleVelocity * dt);

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }
}