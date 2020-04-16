#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));
    const int window_width = 1200;
    const int window_height = 900;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Objects");
    window.setFramerateLimit(60);

    // Массив на указатели на фигуры:
    std::vector<sf::Shape*> objects;
    objects.push_back(new sf::CircleShape(40));
    objects.push_back(new sf::RectangleShape({ 20, 60 }));
    objects.push_back(new sf::CircleShape(50));
    objects.push_back(new sf::CircleShape(10));
    objects.push_back(new sf::RectangleShape({ 100, 20 }));

    sf::ConvexShape convex;
    convex.setPointCount(5);
    convex.setPoint(0, sf::Vector2f(0.f, 0.f));
    convex.setPoint(1, sf::Vector2f(150.f, 10.f));
    convex.setPoint(2, sf::Vector2f(120.f, 90.f));
    convex.setPoint(3, sf::Vector2f(30.f, 100.f));
    convex.setPoint(4, sf::Vector2f(5.f, 50.f));

    objects.push_back(&convex);

    for (int i = 0; i < 90; i++)
        if (rand() % 3 == 0)
            objects.push_back(new sf::CircleShape(rand() % 50));
        else if (rand() % 3 == 0)
            objects.push_back(new sf::RectangleShape({ (float)(rand() % 50), (float)(rand() % 50) }));
        else
        {
            sf::ConvexShape* p = new sf::ConvexShape();
            p->setPointCount(5);
            int spread = 100;
            p->setPoint(0, sf::Vector2f((float)(rand() % spread) - spread/2, (float)(rand() % spread) - spread/2));
            p->setPoint(1, sf::Vector2f((float)(rand() % spread) - spread/2, (float)(rand() % spread) - spread/2));
            p->setPoint(2, sf::Vector2f((float)(rand() % spread) - spread/2, (float)(rand() % spread) - spread/2));
            p->setPoint(3, sf::Vector2f((float)(rand() % spread) - spread/2, (float)(rand() % spread) - spread/2));
            p->setPoint(4, sf::Vector2f((float)(rand() % spread) - spread/2, (float)(rand() % spread) - spread/2));
            objects.push_back(p);
        }
    //Я не очень представляю, как можно создать случайный многоугольникБ поэтому не стал их добавлять

    for (int i = 0; i < objects.size(); i++)
    {
        sf::Vector2f tmp (rand() % window_width, rand() % window_height);
        objects[i]->setPosition(tmp);
        objects[i]->setFillColor({ (unsigned char)rand(), (unsigned char)rand(), (unsigned char)rand() });
    }

    float time = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
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
    objects.clear();

    return EXIT_SUCCESS;
}