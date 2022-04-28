#include <iostream>
#include <cmath>
using std::cout, std::endl;

// Конструктор копирования и оператор присваивания

struct Point 
{
private:
    float x, y;

public:
    Point(float ax, float ay) 
    {
        x = ax;
        y = ay;
    }

    Point() 
    {
        x = 0;
        y = 0;
    }

    Point(const Point& p) 
    {
        x = p.x;
        y = p.y;
    }

    // Оператор присваивания
    // Интересно, что это единственный перегруженный оператор, 
    // который может быть только методом класса
    Point& operator=(const Point& p) 
    {
        x = p.x;
        y = p.y;
        return *this;
    }

    float getX() const 
    {
        return x;
    }

    float getY() const 
    {
        return y;
    }

    float norm() const 
    {
        return std::sqrt(x*x + y*y);
    }

    void normalize() 
    {
        float pnorm = norm();
        x /= pnorm;
        y /= pnorm;
    }

    Point operator+(const Point& right) const 
    {
        Point result = Point(x + right.x, y + right.y);
        return result;
    }
};


ostream& operator<<(ostream& left, Point& right) 
{
    left << "(" << right.getX() << ", " << right.getY() << ")";
    return left;
}

int main() 
{
    /*
    1) Что вызывается в строке ниже?
        Конструктор, оператор присваивания или и то и другое?
    */
    Point a1 = Point(7, 3);
    Point a2(7, 3);
    Point a3 = {7, 3};
    Point a4 {7, 3};

    
    /*
    2) Что вызывается в строке ниже?
        Конструктор, оператор присваивания или и то и другое?
    */
    Point b = a1;

    
    /*
    3) Вызывается ли конструктор в строке ниже?
    */
    Point c;

    /*
    4) Что вызовется в строке ниже?
    */
    c = b;

    // Ответы -- в следующей части
}