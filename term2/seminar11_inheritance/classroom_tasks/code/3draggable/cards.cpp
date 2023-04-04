#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "draggable.hpp"


int main()
{
    std::srand(std::time(nullptr));

    const int width = 800;
    const int height = 600;

    sf::RenderWindow window(sf::VideoMode(width, height), "Cards");
    window.setFramerateLimit(60);


    std::vector<Draggable> draggables;
    for (int i = 0; i < 20; ++i)
    {
        int randomWidth = 10 + rand() % (width / 3);
        int randomHeight = 10 + rand() % (height / 3);
        int randomX = rand() % (width - randomWidth);
        int randomY = rand() % (height - randomHeight);
        sf::Color randomColor {(unsigned char)rand(), (unsigned char)rand(), (unsigned char)rand()};
        draggables.push_back({{(float)randomX, (float)randomY}, {(float)randomWidth, (float)randomHeight}, randomColor});
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});

                for (auto& d : draggables)
                {
                    if (d.onMousePressed(mousePosition))
                        break;
                }
            }

            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
                for (auto& d : draggables)
                {
                    d.onMouseReleased();
                }
            }

            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
                for (auto& d : draggables)
                {
                    d.onMouseMoved(mousePosition);
                }
                
            }
        }
        
        window.clear(sf::Color::Black);
        for (auto it = draggables.crbegin(); it != draggables.crend(); ++it)
        {
            it->draw(window);
        }
        
        window.display();
    }
}


/*
    Задачи:

    1)  Создай класс DraggableWithColorChange, наследник Draggable

        Объекты этого класса представляют собой передвигаемые прямоугольники, но
        в отличии от объектов класса Draggable они должны менять цвет при нажатии на них на красный.
        При отпускании кнопки мыши прямоугольник должен востанавливать свой первоначальный цвет.


    2)  Создай класс DraggableByArea, наследник Draggable

        Один объект этого класса представляет собой 2 прямоугольника.
        При этом перетаскивать объект можно только за один из прямоугольников.
        Второй прямоугольник должен перемещаться вслед за первым.


    3)  Создай класс BaseWindow, наследник DraggableByArea

        Окно -- это прямоугольник, у которого есть полоска наверху (тоже прямоугольник), за которую окно можно передвигать.
        Также, у окна должна быть кнопка закрывания. При нажатии на эту кнопку окно должно исчезать (переставать отрисовываться)
        Используйте класс Button из button.hpp, для этой кнопки. Содержимое окна должно быть пустым.


    4)  Создай класс MessageWindow, наследник BaseWindow

        У объектов этого класса, помимо функционала BaseWindow должен быть текст, в котором отображается некоторая строка.
        А также одна кнопка OK внизу.
        Также такое окно должно быть одним из 4-х типов: Error, Attention, Info, Done
        В зависимости от типа окно должно иметь разный цвет.


    5)  Создай класс QuestionWindow, наследник BaseWindow

        У объектов этого класса, помимо функционала BaseWindow должен быть текст, в котором отображается некоторая строка.
        А также две кнопки внизу: Ok и Cancel


    6)  Создайте программу, в которой, при нажатии на левую кнопку мыши будет создаваться круг

        Но перед созданием кружка будет показываться QuestionWindow и спрашивать действительно ли вы хотите создать кружок.
        При нажатии на Ok, кружок должен создаваться.
        После нажатися на Ok или Cancel или кнопку закрытия окна, окно должно исчезать.
*/