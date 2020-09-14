#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

// Вспомогательная функция
float distance(sf::Vector2f start, sf::Vector2f finish)
{
    return sqrtf((start.x - finish.x)*(start.x - finish.x) + (start.y - finish.y)*(start.y - finish.y));
}


int main()
{
    srand(time(0));
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello world!");
    window.setFramerateLimit(60);

    // Это для надписи вверху слева:
    sf::Font consolas_font;
    if (!consolas_font.loadFromFile("consolas.ttf"))
    {
        cout << "Can't load button font consolas.txt" << endl;
    }
    sf::Text title;
    title.setFont(consolas_font);
    title.setString("Movable rectangles!");
    title.setCharacterSize(28);

    // Создаём прямоугольник:
    sf::RectangleShape rect({200, 150});
    rect.setPosition({300, 300});
    rect.setFillColor(sf::Color(95, 164, 143));
    // Чтобы получить левую верхнюю координату прямоугольника:
    // rect.getPosition()        (вернёт sf::Vector2f)
    // Чтобы получить размеры прямоугольника:
    // rect.getSize()            (вернёт sf::Vector2f)

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2f mouse_position = {(float)event.mouseMove.x, (float)event.mouseMove.y};
                // Вам нужно дописать поведение прямоугольника ниже



            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2f mouse_position = {(float)event.mouseButton.x, (float)event.mouseButton.y};
                // Вам нужно дописать поведение прямоугольника ниже



            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                sf::Vector2f mouse_position = {(float)event.mouseButton.x, (float)event.mouseButton.y};
                // Вам нужно дописать поведение прямоугольника ниже



            }

        }


        window.clear(sf::Color::Black);
        window.draw(rect);
        window.draw(title);
        window.display();
    }

    return 0;
}