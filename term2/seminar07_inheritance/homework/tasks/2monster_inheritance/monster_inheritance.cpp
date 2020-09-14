#include <cmath>
#include <iostream>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


// Создадим класс монстра
class Monster
{
protected:

    // Текстура и спрайт для отрисовки
    sf::Texture& texture;
    sf::Sprite sprite;

    // Здоровье и булевая переменная (жив или нет)
    int health;
    bool is_alive;

    // Скорость движение
    float speed;
    // Точка к которой двигается Монстр
    sf::Vector2f destination;

public:
    Monster(float x, float y, sf::Texture& texture) : texture(texture)
    {
        sprite.setTexture(texture);
        sprite.setOrigin(sprite.getTextureRect().width/2, sprite.getTextureRect().height/2);
        sprite.setScale(sf::Vector2f(0.15, 0.15));

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



// Создадим класс другого монстра - улитки
class Snail : public Monster
{
private:

public:
    // При вызове конструктора Snail, сначала вызовется конструктор Monster
    Snail(float x, float y, sf::Texture& texture) : Monster(x, y, texture)
    {
        // sprite.setPosition(x, y);
        speed = 1;
    }


    // Функция walk у Monster и Snail различается
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
    }
};



int main () 
{

    sf::RenderWindow window(sf::VideoMode(1200, 900), "Creatures: Monster");
    window.setFramerateLimit(60);

    sf::Texture monster_texture;
    monster_texture.loadFromFile("../images/monster.png");

    sf::Texture snail_texture;
    snail_texture.loadFromFile("../images/snail.png");

    Monster a(100, 300, monster_texture);
    a.set_destination(500, 500);

    Snail b(700, 700, snail_texture);
    b.set_destination(500, 500);

    std::vector<Snail> snails = {{100, 100, snail_texture}, {300, 200, snail_texture}, {500, 150, snail_texture}, {200, 600, snail_texture}};


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
                    a.set_destination(event.mouseButton.x, event.mouseButton.y);

                if (event.mouseButton.button == sf::Mouse::Right)
                    b.set_destination(event.mouseButton.x, event.mouseButton.y);
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::M)
                {
                    std::cout << "the M key was pressed" << std::endl;
                }
            }

        }

        window.clear();

        // Двигаем
        a.walk();
        b.walk();

        for (Snail& el : snails)
        {
            el.walk();
            el.draw(window);
        }


        // Рисуем
        a.draw(window);
        b.draw(window);

        window.display();
    }

    return EXIT_SUCCESS;
}