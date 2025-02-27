#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "draggable.hpp"


int main()
{
    std::srand(std::time(nullptr));

    const int width = 800;
    const int height = 600;

    sf::RenderWindow window(sf::VideoMode(width, height), "Cards");
    window.setFramerateLimit(60);


    std::vector<Draggable> draggables;
    for (int i = 0; i < 20; ++i)
    {
        int randomWidth = 20 + rand() % (width / 3);
        int randomHeight = 20 + rand() % (height / 3);
        int randomX = std::rand() % (width - randomWidth);
        int randomY = std::rand() % (height - randomHeight);
        sf::Color randomColor {(unsigned char)rand(), (unsigned char)rand(), (unsigned char)rand()};
        draggables.push_back({window, {(float)randomX, (float)randomY}, {(float)randomWidth, (float)randomHeight}, randomColor});
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            for (auto& d : draggables)
            {
                if (d.handleEvent(event))
                    break;
            }
        }
        
        window.clear(sf::Color::Black);
        for (auto it = draggables.crbegin(); it != draggables.crend(); ++it)
        {
            it->draw();
        }
        
        window.display();
    }
}