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

    float radius = 50;
    sf::CircleShape circle(radius);
    circle.setFillColor({54, 216, 95});
    circle.setPosition({150, 50});
    circle.setOrigin({radius, radius});
    

    float width = 80, height = 160;
    sf::RectangleShape rectangle({width, height});
    rectangle.setFillColor({154, 16, 95});
    rectangle.setPosition({450, 400});
    rectangle.setOrigin({width / 2, height / 2});

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Обрабатывается при нажатии (1 раз во много кадров)
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::G)
                {
                    std::cout << "the G key was pressed" << std::endl;
                    std::cout << "control:" << event.key.control << std::endl;
                    std::cout << "alt:" << event.key.alt << std::endl;
                    std::cout << "shift:" << event.key.shift << std::endl;
                    std::cout << "system:" << event.key.system << std::endl;
                }
            }
			
        }

        // Проверяем, нажата ли клавиша - каждый кадр
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
		    circle.move(0.1f, 0.f);
		}
        window.clear(sf::Color::Black);

        // рисуем круг на скрытом холсте
        window.draw(circle);
        window.draw(rectangle);

        // отображаем содержимое скрытого холста на экран
        window.display();
    }

    return 0;
}