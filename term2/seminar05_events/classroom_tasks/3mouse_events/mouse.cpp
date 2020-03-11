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

            // Обрабатывается при нажатии (1 раз при нажатии)
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }
            }
			
        }

        // Проверяем, зажата ли кнопка мыши - каждый кадр
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
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