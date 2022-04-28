#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

// Программа, которая показывает как можно работать с обработкой событий
// нажатия на клавиши

int main()
{
    srand(time(0));
    // Создаём экземпляр класса окно
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Key handling", sf::Style::Default, settings);
    window.setFramerateLimit(50);
    
    // создаём объект прямоугольника
    float width = 80, height = 160;
    sf::RectangleShape rectangle({width, height});
    rectangle.setFillColor({154, 16, 95});
    rectangle.setPosition({450, 400});
    rectangle.setOrigin({width / 2, height / 2});

    bool kspace = false;
    bool kleft = false;
    bool kup = false;
    
    while (window.isOpen())
    {
        std::cout << "----- New frame -----" << std::endl;
        sf::Event event;
        while (window.pollEvent(event))
        {
            std::cout << "    Event: ";

            if (event.type == sf::Event::Closed)
                window.close();

            std::cout << "key = " << event.key.code << std::endl;
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                    kspace = true;
            }

            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Space)
                    kspace = false;
            }
            if (kspace)
                rectangle.setFillColor({(unsigned char)rand(), (unsigned char)rand(), (unsigned char)rand()});
            std::cout << std::endl;
        }

        window.clear(sf::Color::Black);
        window.draw(rectangle);
        window.display();
    }

    return 0;
}