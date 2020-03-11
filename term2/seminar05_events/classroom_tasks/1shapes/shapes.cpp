#include <SFML/Graphics.hpp>


int main()
{
    // Создаём экземпляр класса окно
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window", sf::Style::Default, settings);

    // Круг
    float radius = 50;
    sf::CircleShape circle(radius);
    circle.setFillColor({54, 216, 95});
    circle.setPosition({150, 50});
    circle.setOrigin({radius, radius});

    // Прямоугольник
    float width = 40, height = 80;
    sf::RectangleShape rectangle({width, height});
    rectangle.setFillColor({154, 16, 95});
    rectangle.setPosition({450, 400});
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

    // Линии
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(400, 500)),
        sf::Vertex(sf::Vector2f(700, 200))
    };

    

    // Главный цикл программы (1 итерация = 1 кадр)
    while (window.isOpen())
    {
        // В начале каждой итерации обрабатываем все события
        // (нажатие клавиш, движение мыши и другое)
        sf::Event event;
        while (window.pollEvent(event))
        {
            // В данном примере проверяем окно на закрытие
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // очистить скрытый холст черным цветом
        window.clear(sf::Color::Black);

        // рисуем круг на скрытом холсте
        window.draw(circle);
        window.draw(rectangle);
        window.draw(convex);
        window.draw(line, 2, sf::Lines);

        // отображаем содержимое скрытого холста на экран
        window.display();
    }

    return 0;
}