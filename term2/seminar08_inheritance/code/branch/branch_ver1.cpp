#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

const float RADTODEG = 180.0/3.14159265358;

class Branch
{
private:
    float width;
    sf::Vector2f position;
    float angle;
    float speed;
    float curve_radius;

    sf::RectangleShape line;

public:

    Branch(float initial_width, sf::Vector2f initial_position, 
           float initial_angle, float initial_curve_radius):
        width(initial_width), position(initial_position), 
        angle(initial_angle), curve_radius(initial_curve_radius)
        {
            speed = 12.0;
        }


    void calculate_next()
    {
        position.x += speed * cos(angle);
        position.y += speed * sin(angle);
        angle += speed / curve_radius;
        if (curve_radius > 5)
            curve_radius -= 0.6;
        if (width > 1)
            width -= 0.03;
    }

    void draw(sf::RenderWindow& window)
    {
        line.setPosition(position);
        line.setSize(sf::Vector2f(speed, width));
        line.setRotation(RADTODEG*angle);
        window.draw(line);
    }

};



int main() 
{
    const int height = 800;
    const int width = 800;
    sf::RenderWindow window(sf::VideoMode(width, height, 32), "Branch");
    window.setFramerateLimit(60);

    Branch b(10, sf::Vector2f(300, 400), 0.2, 200);

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        b.calculate_next();
        b.draw(window);


        window.display();

    }
}