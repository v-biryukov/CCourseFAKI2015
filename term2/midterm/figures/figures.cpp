#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

int main () 
{
    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Arkanoid");
    window.setFramerateLimit(60);



    // Задаём круг
    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color(100, 250, 50));
    circle.setOutlineThickness(10.f);
    circle.setOutlineColor(sf::Color(100, 100, 200));
    circle.setPosition(sf::Vector2f(300, 300));


    // Задаём прямоугольник
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(120.f, 70.f));
    rectangle.setPosition(sf::Vector2f(400.f, 500.f));


    // Задаём надпись
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString("Testing");
    text.setCharacterSize(55);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(sf::Vector2f(200.f, 100.f));
    text.setOrigin(60.f, 40.f);


    // Задаём произвольную форму
    sf::ConvexShape convex;
    convex.setPointCount(5);
    convex.setPoint(0, sf::Vector2f(0.f, 0.f));
    convex.setPoint(1, sf::Vector2f(150.f, 10.f));
    convex.setPoint(2, sf::Vector2f(120.f, 90.f));
    convex.setPoint(3, sf::Vector2f(30.f, 100.f));
    convex.setPoint(4, sf::Vector2f(0.f, 50.f));
    convex.setPosition(sf::Vector2f(50.f, 400.f));
    convex.setFillColor(sf::Color::Red);


    // Линии
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(680.f, 450.f)),
        sf::Vertex(sf::Vector2f(650.f, 300.f)),
        sf::Vertex(sf::Vector2f(740.f, 450.f)),
        sf::Vertex(sf::Vector2f(610.f, 260.f))
    };

    while (window.isOpen()) 
    {
        // Обработка событий
        sf::Event event;
        while(window.pollEvent(event)) 
        {
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) 
            {
                window.close();
            }
            if (event.type == sf::Event::MouseMoved)
            {
                rectangle.setPosition(sf::Vector2f(rectangle.getPosition().x, event.mouseMove.x));
            }

        }
        // Очищаем окно черным цветом
        window.clear(sf::Color::Black);

        // Двигаем круг каждый кадр
        circle.move(0.1, 0.2);

        // Вращаем текст
        text.rotate(0.1);

        // Масштабируем convex
        convex.scale(0.999f, 1.0005f);

        // Рисуем всё
        window.draw(circle);
        window.draw(text);
        window.draw(convex);
        window.draw(line, 4, sf::Lines);
        window.draw(rectangle);


        // Отображам всё нарисованное на временном "холсте" на экран
        window.display();
    }

    return EXIT_SUCCESS;
}
