#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>

const float RADTODEG = 180.0/3.14159265358;


class Flower
{
private:
    float size;
    int number_of_petals;

    sf::Vector2f position;
    
    float width;
    float phi;
    float angular_speed;
    sf::RectangleShape line;

    float get_r(float angle)
    {
        return size * sin(number_of_petals*angle);
    }
public:
    Flower(sf::Vector2f position, float size, int number_of_petals):
        position(position), size(size), number_of_petals(number_of_petals), phi(0)
        {
            angular_speed = 0.02;
            width = 2.0;
            line.setFillColor(sf::Color(220,20,60));
        }

    void calculate_next()
    {
        phi += angular_speed;
    }

    void draw(sf::RenderWindow& window)
    {
        float phi1 = phi - angular_speed / 2;
        float phi2 = phi + angular_speed / 2;
        float r1 = get_r(phi1);
        float x1 = r1 * cos(phi1);
        float y1 = r1 * sin(phi1);
        float r2 = get_r(phi2);
        float x2 = r2 * cos(phi2);
        float y2 = r2 * sin(phi2);
        float l = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
        line.setPosition(position + sf::Vector2f(x1, y1));
        line.setSize(sf::Vector2f(l, width));
        line.setRotation(RADTODEG*atan2(y2-y1, x2-x1));
        window.draw(line);
    }
};


class Branch
{
private:
    float width;
    sf::Vector2f position;
    float angle;
    float speed;
    float curve_radius;

    sf::RectangleShape line;

    float get_random_curve_radius()
    {
        float new_curve_radius = (float)rand() / RAND_MAX * 100.0f + 20.0f;
        int sign = rand() % 2 ? -1 : 1;
        return sign * new_curve_radius;
    }

public:

    static const int max_number_of_branches;
    static const int turn_probability;
    static const int born_probability;
    static const int flower_probability;
    static const float width_decay;

    Branch(float initial_width, sf::Vector2f initial_position, 
           float initial_angle, float initial_curve_radius):
        width(initial_width), position(initial_position), 
        angle(initial_angle), curve_radius(initial_curve_radius)
        {
            speed = 3.0;
            line.setFillColor(sf::Color(139,69,19));
        }


    void calculate_next(std::vector<Branch>& branches, std::vector<Flower>& flowers)
    {
        position.x += speed * cos(angle);
        position.y += speed * sin(angle);
        angle += speed / curve_radius;
             
        if (rand() % 1000 < turn_probability)
        {
            curve_radius = get_random_curve_radius();
        }

        if (rand() % 1000 < born_probability)
        {
            float new_curve_radius = get_random_curve_radius();
            Branch new_branch(width, position, angle, new_curve_radius);
            if (branches.size() < max_number_of_branches)
                branches.push_back(new_branch);
            else
                branches[rand() % max_number_of_branches] = new_branch;
        }

        if (rand() % 1000 < flower_probability)
        {
            Flower new_flower(position, rand() % 40 + 30, (rand()%3)*2 + 3);
            flowers.push_back(new_flower);
            
        }

        if (width > 2)
            width *= width_decay;
    }

    void draw(sf::RenderWindow& window)
    {
        line.setPosition(position);
        line.setSize(sf::Vector2f(speed, width));
        line.setRotation(RADTODEG*angle);
        window.draw(line);
    }
};

const int Branch::max_number_of_branches = 6;
const int Branch::turn_probability = 50;
const int Branch::born_probability = 5;
const int Branch::flower_probability = 2;
const float Branch::width_decay = 0.995;






int main() 
{
    srand(time(NULL));
    const int height = 800;
    const int width = 800;
    sf::RenderWindow window(sf::VideoMode(width, height, 32), "Branch");
    window.setFramerateLimit(60);
    window.clear(sf::Color(245,222,179));

    std::vector<Branch> branches;
    branches.push_back(Branch(4, sf::Vector2f(300, 400), 0.1, 200));

    std::vector<Flower> flowers;

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    window.clear(sf::Color(245,222,179));
                    branches.clear();
                    flowers.clear();
                    branches.push_back(Branch(4, sf::Vector2f(event.mouseButton.x, event.mouseButton.y), 
                        (float)rand() / RAND_MAX * 6.28, 200));
                }
            }
        }

        for (int i = 0; i < branches.size(); ++i)
        {
            branches[i].calculate_next(branches, flowers);
            branches[i].draw(window);
        }

        for (int i = 0; i < flowers.size(); ++i)
        {
            flowers[i].calculate_next();
            flowers[i].draw(window);
        }


        window.display();

    }
}