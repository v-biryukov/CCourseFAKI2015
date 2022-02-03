#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "world.h"

int main() 
{
    sf::RenderWindow window(sf::VideoMode(1200, 900), "Player states");
    window.setFramerateLimit(60);

    double time = 0;
    double dt = 1.0 / 60;

    World world;
    world.addBlock({-500, 770, 2000, 400});
    world.addBlock({-400, 100, 700, 300});
    world.addBlock({600, 500, 300, 120});
    world.addBlock({800, 0, 400, 200});
    world.addBlock({-100, -730, 400, 100});
    world.addBlock({700, -730, 400, 100});
    world.addBlock({1500, -730, 400, 100});
    world.addBlock({1100, -300, 400, 100});

    while (window.isOpen()) 
    {
        sf::Event event;
        while(window.pollEvent(event)) 
        {
            if(event.type == sf::Event::Closed) 
                window.close();

            world.handleEvents(event);
        }
        window.clear(sf::Color::Black);
        world.update(dt);
        world.draw(window);

        window.display();

        time += dt;
    }

    return 0;
}