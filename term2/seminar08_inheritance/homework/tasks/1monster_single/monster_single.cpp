#include <cmath>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


// Создадим класс монстра
class Monster
{
private:

    // Текстура и спрайт для отрисовки
    sf::Texture texture;
    sf::Sprite sprite;

    // Здоровье и булевая переменная (жив или нет)
    int health;
    bool is_alive;

    // Скорость движение
    float speed;
    // Точка к которой двигается Монстр
    sf::Vector2f destination;

public:
    Monster(float x = 0, float y = 0)
    {
        texture.loadFromFile("../images/monster.png");
        sprite.setTexture(texture);
        sprite.setOrigin(sprite.getTextureRect().width/2, sprite.getTextureRect().height/2);
        sprite.setScale(sf::Vector2f(0.2, 0.2));

        sprite.setPosition(x, y);

        health = 100;
        is_alive = false;
        speed = 5;
    }

    void hurt(int damage)
    {
        health -= damage;
        if (health <= 0)
            is_alive = false;
    }

    void heal(int heal_power)
    {
        if (is_alive)
            health += heal_power;
        if (health > 100)
            health = 100;
    }

    void walk()
    {
        float dx = destination.x - sprite.getPosition().x;
        float dy = destination.y - sprite.getPosition().y;
        float norm = sqrt(dx*dx + dy*dy);
        if (norm > 10)
        {
            dx = speed*dx/norm;
            dy = speed*dy/norm;
        }

        sprite.move(dx, dy);
        sprite.rotate(3);
    }

    void set_destination(float x, float y)
    {
        destination.x = x;
        destination.y = y;
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(sprite);
    }
};



int main () 
{

    sf::RenderWindow window(sf::VideoMode(1200, 900), "Creatures: Monster");
    window.setFramerateLimit(60);

    Monster a(100, 300);
    a.set_destination(500, 500);


    while (window.isOpen()) 
    {
        sf::Event event;
        while(window.pollEvent(event)) 
        {
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) 
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    a.set_destination(event.mouseButton.x, event.mouseButton.y);
                }
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::M)
                {
                    std::cout << "the M key was pressed" << std::endl;
                    std::cout << "control:" << event.key.control << std::endl;
                    std::cout << "alt:" << event.key.alt << std::endl;
                    std::cout << "shift:" << event.key.shift << std::endl;
                    std::cout << "system:" << event.key.system << std::endl;
                }
            }

        }

        window.clear();

        // Двигаем
        a.walk();
        a.draw(window);

        window.display();
    }

    return EXIT_SUCCESS;
}