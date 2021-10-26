#include <iostream>
#include <string>
#include <cstdlib>

struct Vector2f
{
    float x, y;
};

Vector2f operator+(Vector2f left, Vector2f right)
{
    Vector2f result = {left.x + right.x, left.y + right.y};
    return result;
}
Vector2f operator*(Vector2f left, float right)
{
    Vector2f result = {left.x * right, left.y * right};
    return result;
}
Vector2f operator*(float left, Vector2f right)
{
    Vector2f result = {left * right.x, left * right.y};
    return result;
}


// Класс Скелет
class Skeleton
{
private:
    Vector2f position;
    Vector2f velocity;

    int max_health, health;
    bool is_alive;

public:

    Skeleton(Vector2f position = {0, 0}, int max_health = 100) :
                position(position), max_health(max_health), is_alive(true)
    {
        health = max_health;
        // Скелет может двигаться только по горизонтали:
        if (rand() % 2)
            velocity = {5, 0};
        else
            velocity = {-5, 0};
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
        if (health > max_health)
            health = max_health;
    }

    void say()
    {
        std::cout << "<Bones are creaking>" << std::endl;
    }

    void move(float dt)
    {
        position = position + velocity * dt;
    }

    void print_info()
    {
        std::cout << "Skeleton: position = {" << position.x << ", " << position.y << "}, "
                     "velocity = {" << velocity.x << ", " << velocity.y << "}, " 
                     "health = " << health << ", max_health = " << max_health << std::endl;
    }
};


// Класс призрак
class Ghost
{
private:
    Vector2f position;
    Vector2f velocity;

    int max_health, health;
    bool is_alive;

    bool is_regeneratable;

public:

    Ghost(Vector2f position = {0, 0}, int max_health = 100) :
                position(position), max_health(max_health), is_alive(true)
    {
        health = max_health;
        // Призрак движется в произвольном направлении
        velocity = {(float)(rand() % 10 - 5), (float)(rand() % 10 - 5)};
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
        if (health > max_health)
            health = max_health;
    }

    void say()
    {
        std::cout << "oooOOOoooOOOoooOOOooo" << std::endl;
    }

    void move(float dt)
    {
        if (is_regeneratable)
            heal(1);
        position = position + velocity * dt;
    }

    void print_info()
    {
        std::cout << "Ghost: position = {" << position.x << ", " << position.y << "}, "
                     "velocity = {" << velocity.x << ", " << velocity.y << "}, " 
                     "health = " << health << ", max_health = " << max_health << std::endl;
    }
};


// Класс Лягушка
class Frog
{
private:
    Vector2f position;
    Vector2f velocity;

    int max_health, health;
    bool is_alive;

    int talkativeness;

public:

    Frog(Vector2f position = {0, 0}, int max_health = 100, int talkativeness = 3) :
                position(position), max_health(max_health), is_alive(true), talkativeness(talkativeness)
    {
        health = max_health;
        // Лягушка прыгает вверх
        velocity = {(float)(rand() % 10 - 5), (float)(rand() % 10)};
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
        if (health > max_health)
            health = max_health;
    }

    void say()
    {
        for (int i = 0; i < talkativeness; i++)
            std::cout << "Kwaak ";
        std::cout << std::endl;
    }

    void move(float dt)
    {
        // Чтобы лягушка прыгала, нужна гравитация
        velocity.y -= 9.8 * dt;
        if (position.y <= 0)
            velocity.y = 0;
        position = position + velocity * dt;
    }

    void print_info()
    {
        std::cout << "Frog: position = {" << position.x << ", " << position.y << "}, "
                     "velocity = {" << velocity.x << ", " << velocity.y << "}, " 
                     "health = " << health << ", max_health = " << max_health << std::endl;
    }
};


int main()
{
    Skeleton a;
    a.say();
    
    Ghost b;
    b.say();

    Frog c {{0, 0}, 50, 10};
    c.say();


    a.print_info();
    a.hurt(80);
    a.print_info();


    // Задание 1: 
    // Создайте класс-родитель Monster, такой, чтобы классы Skeleton, Ghost и Frog от него наследовались.
    // Сами определите те методы и поля, которые должны описываться в классе Monster 
    //        и которые должны описываться в классах потомках


    // Задание 2: 
    // Напишите функцию resurrect, которая будет "воскрешать" монстра (независимо от того, какой это монстр)

    // Задание 3:
    // Создайте класс SkeletonPirate - скелета-пирата. Этот монстр должен вести себя также как и скелет,
    // но при вызове функции say, он должен говорить  "Aaarrrgghh!"
    // Протестируте класс SkeletonPirate в main


    // Задание 4:
    // Можно ли написать так и почему?
    // Monster m = a;
    // m.say();

    // А можно ли написать так и почему?
    // Monster m;
    // Skeleton s = m;
    // s.say();



    // Задание 5:
    // Можно ли написать так и почему?
    // Monster* pm = &a;
    // pm->say();


    // А можно ли написать так и почему?
    // Monster m;
    // Skeleton* ps = &m;
    // ps->say();

    // Протестируйте ваши догадки в заданиях 4 и 5.
}