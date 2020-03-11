#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>


int main()
{
    srand(time(0));
    // Создаём экземпляр класса окно
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Key handling", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    sf::RectangleShape a({200, 60});
    a.setPosition(300, 200);
    a.setOrigin(a.getSize().x / 2, a.getSize().y / 2);


    sf::RectangleShape b({70, 160});
    b.setPosition(500, 400);
    b.setOrigin(b.getSize().x / 2, b.getSize().y / 2);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseMoved)
            {
                a.setPosition(event.mouseMove.x, event.mouseMove.y);
            }
        }

        window.clear(sf::Color::Black);

        // рисуем круг на скрытом холсте
        window.draw(a);
        window.draw(b);

        // отображаем содержимое скрытого холста на экран
        window.display();
    }

    return 0;
}