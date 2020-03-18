#include <iostream>
#include <cmath>
#include <list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

// Вспомогательные функции
float distance(sf::Vector2f start, sf::Vector2f finish)
{
    return sqrtf((start.x - finish.x)*(start.x - finish.x) + (start.y - finish.y)*(start.y - finish.y));
}

void draw_line(sf::RenderWindow& window, sf::Vector2f start, sf::Vector2f finish, sf::Color color = sf::Color::White)
{
    sf::Vertex line_vertices[2] = {sf::Vertex(start, color), sf::Vertex(finish, color)};
    window.draw(line_vertices, 2, sf::Lines);
}


struct Ball
{
    sf::Vector2f position;
    float radius;
    bool is_choosen; // Выбран ли этот шар

    Ball(sf::Vector2f position, float radius) : position(position), radius(radius)
    {
        is_choosen = false;
    }

    void draw(sf::RenderWindow& window)
    {
        // Тут рисуем белый кружочек
        sf::CircleShape circle(radius);
        circle.setFillColor(sf::Color::White);
        circle.setOrigin({radius, radius});
        circle.setPosition(position);
        window.draw(circle);

        if (is_choosen)
        {
            // Тут мы рисуем "уголки"
            float fraction = 0.7;
            draw_line(window, {position.x - radius, position.y + radius}, {position.x - radius, position.y + radius*fraction});
            draw_line(window, {position.x - radius, position.y + radius}, {position.x - fraction * radius, position.y + radius});

            draw_line(window, {position.x + radius, position.y + radius}, {position.x + radius, position.y + radius*fraction});
            draw_line(window, {position.x + radius, position.y + radius}, {position.x + radius*fraction, position.y + radius});

            draw_line(window, {position.x + radius, position.y - radius}, {position.x + radius*fraction, position.y - radius});
            draw_line(window, {position.x + radius, position.y - radius}, {position.x + radius, position.y - radius*fraction});

            draw_line(window, {position.x - radius, position.y - radius}, {position.x - radius*fraction, position.y - radius});
            draw_line(window, {position.x - radius, position.y - radius}, {position.x - radius, position.y - radius*fraction});
        }
    }
};


int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Move and Delete!", sf::Style::Close, settings);
    window.setFramerateLimit(60);


    // Создаём связный список из шариков
    // Связыный список -- потому что нам нужно будет постоянно удалять и добавлять в этот список
    std::list<Ball> balls;
    balls.push_back(Ball({200, 200}, 26));
    balls.push_back(Ball({400, 300}, 20));
    balls.push_back(Ball({500, 100}, 16));
    balls.push_back(Ball({200, 400}, 18));
    balls.push_back(Ball({350, 150}, 22));
    balls.push_back(Ball({750, 400}, 21));

    // Создаём прямоугольник выделения
    // Обратите внимание на четвёртый параметр sf::Color(150, 150, 240, 50)
    // Это alpha - прозрачность      0 = полностью прозрачный     255 = непрозрачный
    sf::RectangleShape selection_rect;
    selection_rect.setFillColor(sf::Color(150, 150, 240, 50));
    selection_rect.setOutlineColor(sf::Color(200, 200, 255));
    selection_rect.setOutlineThickness(1);

    // Специальная переменная, которая будет показывать, что мы находимся в режиме выделения
    bool is_selecting = false;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // При движении мыши
            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2f mouse_position = {(float)event.mouseMove.x, (float)event.mouseMove.y};
                
                // Если мы находимся в режиме выделения, то меняем прямоугольник выделения
                if (is_selecting)
                    selection_rect.setSize(mouse_position - selection_rect.getPosition());

            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2f mouse_position = {(float)event.mouseButton.x, (float)event.mouseButton.y};
                // При нажатии левой кнопки мыши:
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Если не зажат левый Shift, то снимаем все выделения
                    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
                    {
                        for (Ball& b : balls)
                            b.is_choosen = false;
                    }

                    // Проверяем попал ли курсор в какой-нибудь шарик, если попал - выделяем
                    for (Ball& b : balls)
                    {
                        if (distance(mouse_position, b.position) < b.radius)
                        {
                            b.is_choosen = true;
                            break;
                        }
                    }

                    // Задаём новое положения прямоугольника выделения
                    is_selecting = true;
                    selection_rect.setPosition(mouse_position);
                    selection_rect.setSize({0, 0});

                }

                // При нажатии правой кнопки мыши - создаём случайный шарик:
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    balls.push_back(Ball(mouse_position, 5 + rand() % 40));
                }


            }

            // При отпускании кнопки мыши
            if (event.type == sf::Event::MouseButtonReleased)
            {
                sf::Vector2f mouse_position = {(float)event.mouseButton.x, (float)event.mouseButton.y};
                // Выходим из режима выделения
                is_selecting = false;



            }

        }


        window.clear(sf::Color::Black);
        
        // Рисуем все шарики
        for (Ball& b : balls)
        {
            b.draw(window);
        }

        // Рисуем прямоугольник выделения
        if (is_selecting)
            window.draw(selection_rect);

        window.display();
    }

    return 0;
}