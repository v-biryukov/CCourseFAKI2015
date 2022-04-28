#include <cmath>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Monster
{
protected:

    sf::Texture m_texture;
    sf::Sprite m_sprite;

    int m_health;
    bool m_isAlive;
    float m_speed;

public:
    Monster(sf::Vector2f position, float speed) : m_speed(speed)
    {
        m_texture.loadFromFile("./images/monster.png");
        m_sprite.setTexture(m_texture);
        m_sprite.setOrigin(m_sprite.getTextureRect().width/2, m_sprite.getTextureRect().height/2);
        m_sprite.setScale(sf::Vector2f(0.2, 0.2));
        m_sprite.setPosition(position);

        m_health = 100;
        m_isAlive = false;
    }

    void hurt(int damage)
    {
        m_health -= damage;
        if (m_health <= 0)
            m_isAlive = false;
    }

    void heal(int healPower)
    {
        if (m_isAlive)
            m_health += healPower;
        if (m_health > 100)
            m_health = 100;
    }

    virtual void walk(float dt) = 0;

    void draw(sf::RenderWindow& window)
    {
        window.draw(m_sprite);
    }
};



class Chupacabra : public Monster
{
private:
    sf::Vector2f m_direction;
public:

    Chupacabra(sf::Vector2f position, float speed, sf::Vector2f direction) : Monster(position, speed), m_direction{direction}
    {
        m_texture.loadFromFile("./images/chupacabra.png");

        float directionNorm = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        direction.x /= directionNorm;
        direction.y /= directionNorm;
    }

    void walk(float dt)
    {
        m_sprite.move(m_speed * m_direction.x * dt, m_speed * m_direction.y * dt);
        m_sprite.rotate(2);
    }
};


class Snail : public Monster
{
private:

public:

    Snail(sf::Vector2f position, float speed) : Monster(position, speed)
    {
        m_texture.loadFromFile("./images/snail.png");
    }

    void walk(float dt)
    {
        m_sprite.move(m_speed * dt, 0);
    }
};



class Bee : public Monster
{
private:
    sf::Vector2f center;
    float radius;
    float angle = 0;
public:

    Bee(sf::Vector2f position, float speed, sf::Vector2f center, float radius) : Monster{position, speed}, center{center}, radius{radius}
    {
        m_texture.loadFromFile("./images/bee.png");
    }

    void walk(float dt)
    {
        angle += m_speed * dt / radius;
        m_sprite.setPosition(center + sf::Vector2f{radius * std::cos(angle), radius * std::sin(angle)});
    }
};



class Lobster : public Monster
{
private:

public:

    Lobster(sf::Vector2f position, float speed) : Monster(position, speed)
    {
        m_texture.loadFromFile("./images/lobster.png");
    }

    void walk(float dt)
    {
        m_sprite.move(m_speed * dt, 0);
    }
};


class Pumpkin : public Monster
{
private:
    sf::Vector2f center;
    float radius;
    float angle = 0;
public:

    Pumpkin(sf::Vector2f position, float speed, sf::Vector2f center, float radius) : Monster{position, speed}, center{center}, radius{radius}
    {
        m_texture.loadFromFile("./images/pumpkin.png");
    }

    void walk(float dt)
    {
        angle += m_speed * dt / radius;
        m_sprite.setPosition(center + sf::Vector2f{radius * std::cos(angle), radius * std::sin(angle)});
    }
};



class Star : public Monster
{
private:
    sf::Vector2f m_direction;
public:

    Star(sf::Vector2f position, float speed, sf::Vector2f direction) : Monster(position, speed), m_direction{direction}
    {
        m_texture.loadFromFile("./images/star.png");

        float directionNorm = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        direction.x /= directionNorm;
        direction.y /= directionNorm;
    }

    void walk(float dt)
    {
        m_sprite.move(m_speed * m_direction.x * dt, m_speed * m_direction.y * dt);
        m_sprite.rotate(2);
    }
};


int main () 
{

    sf::RenderWindow window(sf::VideoMode(1200, 900), "Creatures: Monster");
    window.setFramerateLimit(60);
    float dt = 1.0 / 60;

    Chupacabra a({100, 300}, 25, {1, 1});
    Snail b({700, 700}, 10);
    Bee c({400, 400}, 100, {400, 400}, 50);

    Lobster d({100, 700}, 30);
    Pumpkin e({600, 200}, 50, {600, 200}, 100);
    Star f({600, 100}, 80, {-1, 1});


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

        a.walk(dt);
        b.walk(dt);
        c.walk(dt);
        d.walk(dt);
        e.walk(dt);
        f.walk(dt);
   
        a.draw(window);
        b.draw(window);
        c.draw(window);
        d.draw(window);
        e.draw(window);
        f.draw(window);

        window.display();
    }

    return 0;
}



/*
    Задание:

    В этой программе представлена иерархия классов монстров

    Используйте паттерн проектирования Мост, чтобы сделать код болле гибким
    В этой программе есть повторяющиеся участки кода, отвечающие за перемещение монстров
    Ваше задача заключается в том, чтобы вынести эти участки кода в отдельную иерархию классов

    Для этого создайте абстрактный класс Movement и отнаследуйте от него классы:
    PlaneMovement        --  движение по оси X
    DirectionalMovement  --  движение вдоль заданного направления
    CircleMovement       --  движение по кругу


    Класс Monster должен содержать указатель на объект типа Movement


*/