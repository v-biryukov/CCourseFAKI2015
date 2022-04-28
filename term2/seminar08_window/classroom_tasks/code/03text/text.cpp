#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

// Программа, которая рисует круг, пр

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Draw Text");
    
    // Загружаем шрифт
    sf::Font font;
    if (!font.loadFromFile("consola.ttf")) 
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

    // Очищаем скрытый холст и рисуем там наши объекты
    window.clear(sf::Color::Black);
    window.draw(text);

    // Отображаем скрытый холст на экране
    window.display();

    sf::sleep(sf::seconds(100));
    return 0;
}