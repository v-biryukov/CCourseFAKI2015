#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

// Программа, которая демонстрирует работу с текстом в SFML

int main()
{
    srand(time(0));
    // Создаём экземпляр класса окно
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Key handling", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    // Сначала создаём объект шрифта и загружаем его из файла
    // Файл octin.ttf должен находится в той же папке, что и исполняемый файл
    sf::Font font;
    if (!font.loadFromFile("octin.ttf"))
    {
        // Если шрифт не удалось загрузить - печатаем ошибку
        std::cout << "Error! Can't load font!" << std::endl;
        std::exit(1);
    }

    // Создаём объект текста
    // Задаём шрифт, строку, размер шрифта(в пикселях), цвет, стиль и положение
    sf::Text text;
    text.setFont(font);
    text.setString("Hello world");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color(70, 160, 100));
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition({300, 200});

    // Основной цикл программы (1 итерация = 1 кадр)
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Проверяем, зажата ли кнопка мыши
        // и, если да, то вращаем текст на 1 градус
        // и задаём в содержимое текста - x координату мыши
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