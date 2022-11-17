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

Vector2f& operator+=(Vector2f& left, Vector2f right)
{
    left = left + right;
    return left;
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



class Skeleton
{
private:
    Vector2f mPosition {0, 0};
    Vector2f mVelocity {0, 0};

    int mMaxmHealth  {100};
    int mHealth      {100};
    bool mIsAlive    {true};

public:

    Skeleton() {}

    Skeleton(Vector2f position, int maxmHealth)
            : mPosition{position}, mMaxmHealth{maxmHealth}, mIsAlive{true}
    {
        mHealth = maxmHealth;
        // Скелет может двигаться только по горизонтали:
        if (rand() % 2)
            mVelocity = {5, 0};
        else
            mVelocity = {-5, 0};
    }

    void hurt(int damage)
    {
        mHealth -= damage;
        if (mHealth <= 0)
            mIsAlive = false;
    }

    void heal(int healPower)
    {
        if (mIsAlive)
            mHealth += healPower;

        if (mHealth > mMaxmHealth)
            mHealth = mMaxmHealth;
    }

    void say()
    {
        std::cout << "<Bones are creaking>" << std::endl;
    }

    void move(float dt)
    {
        mPosition += mVelocity * dt;
    }

    void printInfo()
    {
        std::cout << "Skeleton: position = {" << mPosition.x << ", " << mPosition.y << "}, "
                     "velocity = {" << mVelocity.x << ", " << mVelocity.y << "}, " 
                     "health = " << mHealth << ", max health = " << mMaxmHealth << std::endl;
    }
};


class Ghost
{
private:
    Vector2f mPosition {0, 0};
    Vector2f mVelocity {0, 0};

    int mMaxmHealth  {100};
    int mHealth      {100};
    bool mIsAlive    {true};

    bool isRegeneratable {true};

public:

    Ghost(Vector2f position = {0, 0}, int maxmHealth = 100) :
                mPosition(position), mMaxmHealth(maxmHealth), mIsAlive(true)
    {
        mHealth = maxmHealth;
        // Призрак движется в произвольном направлении
        mVelocity = {(float)(rand() % 10 - 5), (float)(rand() % 10 - 5)};
    }

    void hurt(int damage)
    {
        mHealth -= damage;
        if (mHealth <= 0)
            mIsAlive = false;
    }

    void heal(int healPower)
    {
        if (mIsAlive) 
            mHealth += healPower;

        if (mHealth > mMaxmHealth)
            mHealth = mMaxmHealth;
    }


    void say()
    {
        std::cout << "oooOOOoooOOOoooOOOooo" << std::endl;
    }

    void move(float dt)
    {
        if (isRegeneratable)
            heal(1);

        mPosition += mVelocity * dt;
    }

    void printInfo()
    {
        std::cout << "Ghost: position = {" << mPosition.x << ", " << mPosition.y << "}, "
                     "velocity = {" << mVelocity.x << ", " << mVelocity.y << "}, " 
                     "health = " << mHealth << ", max health = " << mMaxmHealth << std::endl;
    }
};


class Frog
{
private:
    Vector2f mPosition {0, 0};
    Vector2f mVelocity {0, 0};

    int mMaxmHealth  {100};
    int mHealth      {100};
    bool mIsAlive    {true};

    int talkativeness {3};

public:

    Frog(Vector2f position, int maxmHealth, int talkativeness) :
                mPosition(position), mMaxmHealth(maxmHealth), mIsAlive(true), talkativeness(talkativeness)
    {
        mHealth = maxmHealth;
        // Лягушка прыгает вверх
        mVelocity = {(float)(rand() % 10 - 5), (float)(rand() % 10)};
    }

    void hurt(int damage)
    {
        mHealth -= damage;
        if (mHealth <= 0)
            mIsAlive = false;
    }

    void heal(int healPower)
    {
        if (mIsAlive)
            mHealth += healPower;

        if (mHealth > mMaxmHealth)
            mHealth = mMaxmHealth;
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
        mVelocity.y -= 9.8 * dt;
        if (mPosition.y <= 0)
            mVelocity.y = 0;

        mPosition += mVelocity * dt;
    }

    void printInfo()
    {
        std::cout << "Frog: position = {" << mPosition.x << ", " << mPosition.y << "}, "
                     "velocity = {" << mVelocity.x << ", " << mVelocity.y << "}, " 
                     "health = " << mHealth << ", max health = " << mMaxmHealth << std::endl;
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


    a.printInfo();
    a.hurt(80);
    a.printInfo();
}

/*
    Задачи:

        1)  Создайте класс-родитель Monster, такой, чтобы классы Skeleton, Ghost и Frog от него наследовались.
            Сами определите те методы и поля, которые должны описываться в классе Monster 
            и которые должны описываться в классах потомках.

        2)  Напишите функцию resurrect, которая будет "воскрешать" монстра.

        3)  Создайте класс SkeletonPirate - скелета-пирата. Этот монстр должен вести себя также как и скелет,
            но при вызове функции say, он должен говорить  "Aaarrrgghh!".
            Протестируте класс SkeletonPirate в main.
*/