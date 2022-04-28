#include <iostream>
#include <cmath>
using namespace std;

// Конструктор копирования и оператор присваивания
// Оператор присваивания:
// Интересно, что это единственный оператор, который может быть определён только внутри класса
// Оператор присваивания должен вернуть ссылку на экземпляр (т.е. *this)

struct Point 
{
private:
    float x, y;

public:
    Point(float ax, float ay) 
    {
        cout << "Constructor(float, float)" << endl;
        x = ax;
        y = ay;
    }

    Point() 
    {
        cout << "Default Constructor()" << endl;
        x = 0;
        y = 0;
    }

    Point(const Point& p) 
    {
        cout << "Copy Constructor(Point)" << endl;
        x = p.x;
        y = p.y;
    }


    Point& operator=(const Point& p) 
    {
        cout << "Assign operator" << endl;
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
        cout << "Addition operator" << endl;
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
    // Запустите эту программу, чтобы понять какие именно методы запускаются

    /*
    1) Что вызывается в строке ниже?
        Конструктор, оператор присваивания или и то и другое?
    */
    cout << "Part 1" << endl;
    Point a1 = Point(7, 3);
    Point a2(7, 3);
    Point a3 = {7, 3};
    Point a4 {7, 3};


    
    /*
    2) Что вызывается в строке ниже?
        Конструктор, оператор присваивания или и то и другое?
    */
    cout << "Part 2" << endl;
    Point b = a1;

    
    /*
    3) Вызывается ли конструктор в строке ниже?
    */
    cout << "Part 3" << endl;
    Point c;

    /*
    4) Что вызовется в строке ниже?
    */
    cout << "Part 4" << endl;
    c = b;


    /*
    5) Что вызовется в строке ниже?
    */
    cout << "Part 5" << endl;
    c = a1 + a2;
}