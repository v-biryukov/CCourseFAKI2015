#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main () 
{

    sf::RenderWindow window(sf::VideoMode(1200, 900), "Platformer");
    window.setFramerateLimit(60);

    sf::Texture t;
    if (!t.loadFromFile("./wood.png"))
    {
        exit(1);
    }


    while (window.isOpen()) 
    {
        sf::Event event;
        while(window.pollEvent(event)) 
        {
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) 
            {
                window.close();
            }

        }
        window.display();
    }

    return EXIT_SUCCESS;
}