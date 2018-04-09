#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
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
    static const float width_decay;

    Branch(float initial_width, sf::Vector2f initial_position, 
           float initial_angle, float initial_curve_radius):
        width(initial_width), position(initial_position), 
        angle(initial_angle), curve_radius(initial_curve_radius)
        {
            speed = 3.0;
        }


    void calculate_next(std::vector<Branch>& branches)
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

        if (width > 1.5)
            width *= 0.995;
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
const int Branch::born_probability = 6;
const float Branch::width_decay = 0.995;


int main() 
{
    srand(time(NULL));
    const int height = 800;
    const int width = 800;
    sf::RenderWindow window(sf::VideoMode(width, height, 32), "Branch");
    window.setFramerateLimit(60);

    std::vector<Branch> branches;
    branches.push_back(Branch(4, sf::Vector2f(300, 400), 0.2, 200));

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
                    window.clear();
                    branches.clear();
                    branches.push_back(Branch(4, sf::Vector2f(event.mouseButton.x, event.mouseButton.y), 
                        (float)rand() / RAND_MAX * 6.28, 200));
                }
            }
        }

        for (int i = 0; i < branches.size(); ++i)
        {
            branches[i].calculate_next(branches);
            branches[i].draw(window);
        }


        window.display();

    }
}