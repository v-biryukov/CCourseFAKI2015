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

    sf::Font font;
    if (!font.loadFromFile("octin.ttf"))
    {
        std::cout << "Error! Can't load font!" << std::endl;
        std::exit(1);
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Hello world");
    text.setCharacterSize(24); // character size in pixels!
    text.setFillColor(sf::Color(43, 156, 78));
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition({400, 400});

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Проверяем, зажата ли кнопка мыши - каждый кадр
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            text.rotate(1);
            text.setString(std::to_string(sf::Mouse::getPosition(window).x));
        }
        window.clear(sf::Color::Black);

        window.draw(text);

        // отображаем содержимое скрытого холста на экран
        window.display();
    }

    return 0;
}