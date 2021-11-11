#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

int main () 
{
    srand(time(0));
    const int window_width = 1200;
    const int window_height = 900;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Objects");
    window.setFramerateLimit(60);

    // Массив на указатели на фигуры:
    std::vector<sf::Shape*> objects;
    objects.push_back(new sf::CircleShape(40));
    objects.push_back(new sf::RectangleShape({20, 60}));
    objects.push_back(new sf::CircleShape(50));
    objects.push_back(new sf::CircleShape(10));
    objects.push_back(new sf::RectangleShape({100, 20}));

    for (int i = 0; i < objects.size(); i++)
    {
        objects[i]->setPosition({rand() % window_width, rand() % window_height});
    }

    float time = 0;
    while (window.isOpen()) 
    {
        sf::Event event;
        while(window.pollEvent(event)) 
        {
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) 
            {
                window.close();
            }

        }

        for (int i = 0; i < objects.size(); i++)
        {
            window.draw(*objects[i]);
        }

        window.display();

        time += 1.0 / 60;
    }

    return EXIT_SUCCESS;
}




// Задание 1: 
// Измените цвет всех объектов на случайный

// Задание 2: 
// Добавьте в objects указатель на тип ConvexShape
// Создайте пятиугольник

// Задание 3:
// Добавьте в objects - 100 случайных объектов (круги, прямоугольники или многоугольники)

// Задание 4:
// Освободите память
