#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

// Программа, которая рисует круг, пр

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Draw Shapes", sf::Style::Default, settings);
    
    // Круг
    float radius = 50;
    sf::CircleShape circle(radius);
    circle.setFillColor({54, 216, 95});
    circle.setPosition({150, 50});
    circle.setOrigin({radius, radius});

    // Прямоугольник
    float width = 60, height = 120;
    sf::RectangleShape rectangle({width, height});
    rectangle.setFillColor({154, 16, 95});
    rectangle.setPosition({350, 300});
    rectangle.setOrigin({width / 2, height / 2});


    // Фигура сложной формы
    sf::ConvexShape convex;
    convex.setPointCount(5);
    convex.setPoint(0, sf::Vector2f(0.f, 0.f));
    convex.setPoint(1, sf::Vector2f(150.f, 10.f));
    convex.setPoint(2, sf::Vector2f(120.f, 90.f));
    convex.setPoint(3, sf::Vector2f(30.f, 100.f));
    convex.setPoint(4, sf::Vector2f(0.f, 50.f));
    convex.setFillColor({65, 146, 123});
    convex.setPosition({100, 400});

    // Линии, массив из точек
    sf::Vertex lines[] = 
    {
        sf::Vertex(sf::Vector2f(400, 500)),
        sf::Vertex(sf::Vector2f(700, 200)),
        sf::Vertex(sf::Vector2f(800, 300)),
        sf::Vertex(sf::Vector2f(400, 400))
    };

    // Очищаем скрытый холст и рисуем там наши объекты
    window.clear(sf::Color::Black);
    window.draw(circle);
    window.draw(rectangle);
    window.draw(convex);
    window.draw(lines, 4, sf::Lines);

    // Отображаем скрытый холст на экране
    window.display();

    sf::sleep(sf::seconds(100));
    return 0;
}