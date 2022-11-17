#include <iostream>
#include <cmath>

const float pi = 3.14159265;

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

Vector2f& operator+=(Vector2f& left, Vector2f right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}



class Circle
{
private:
    Vector2f position;
    float radius;

public:

    Circle(float radius) : radius(radius), position({0, 0})
    {
    }

    Vector2f getPosition()
    {
        return position;
    }

    void setPosition(const Vector2f& newPosition)
    {
        position = newPosition;
    }


    float calculatePerimeter()
    {
        return 2 * pi * radius;
    }

    float calculateArea()
    {
        return pi * radius * radius;
    }
};



class Triangle
{
private:
    Vector2f position;

    Vector2f pointA;
    Vector2f pointB;
    Vector2f pointC;

    float getDistance(Vector2f a, Vector2f b)
    {
        return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

public:

    Triangle(Vector2f pointA, Vector2f pointB, Vector2f pointC) : 
             position({0, 0}), pointA(pointA), pointB(pointB), pointC(pointC)
    {
    }

    Vector2f getPosition()
    {
        return position;
    }

    void setPosition(Vector2f newPosition)
    {
        position = newPosition;
    }

    float calculatePerimeter()
    {
        return getDistance(pointA, pointB) + getDistance(pointB, pointC) + getDistance(pointC, pointA);
    }

    float calculateArea()
    {
        float a = getDistance(pointA, pointB);
        float b = getDistance(pointB, pointC);
        float c = getDistance(pointC, pointA);

        float p = (a + b + c) / 2;
        return std::sqrt(p * (p - a) * (p - b) * (p - c));
    }
};


int main()
{
    Circle a(7);
    std::cout << a.calculatePerimeter() << " " << a.calculateArea() << std::endl;

    Triangle b({5, 2}, {-7, 5}, {4, 4});
    std::cout << b.calculatePerimeter() << " " << b.calculateArea() << std::endl;

}

/*
    Задачи:

        1)  Создайте свой класс Rectangle.
            Протестируйте его на следующем участке кода:

                Rectangle b(12, 8);
                std::cout << b.calculatePerimeter() << " " << b.calculateArea() << std::endl;


        2)  Создайте свой основной класс Figure и проведите наследование от него к класам Circle, Triangle и Rectangle.

        3)  Добавьте метод void move(Vector2f change) в класс Figure. Этот метод должен изменять поле position
            Так как остальные классы наследуются от Figure, то этот метод можно будет вызвать у всех объектов дочерних классов.

*/