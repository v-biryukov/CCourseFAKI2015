#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

// Создание экземпляров класса в куче. Операторы new и delete.

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
        cout << "Empty Constructor" << endl;
        x = 0;
        y = 0;
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
    // Создание экземпляров класса в куче
    // Malloc выделяет память, но не вызывает конструктор
    cout << "Malloc:" << endl;
    Point* p = (Point*)malloc(sizeof(Point));
    
    // New выделяет память и вызывает конструктор
    cout << "New:" << endl;
    Point* q = new Point(7, 3);

    cout << "------------------" << endl;
    cout << "Point created with malloc = " << *p << endl;
    cout << "Point created with new = " << *q << endl;

    free(p);
    delete q;

    // Создадим 10 экземпляров класса Point в куче
    // Для каждого из них вызовется конструктор по умолчанию
    Point* parray = new Point[10];
    delete [] parray;
}