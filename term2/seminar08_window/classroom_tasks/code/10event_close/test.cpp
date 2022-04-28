#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

// Окно закрывается при нажатии на крестик
// Но программа (главный цикл) продолжает работать

int main() 
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Close this window");
    window.setFramerateLimit(60);

    while (true) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.display();
    }
}