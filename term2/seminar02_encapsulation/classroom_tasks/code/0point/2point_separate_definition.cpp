#include <iostream>
#include <cmath>
using std::cout, std::endl;

/*
    Методы могут быть объявлены внутри класса, а описаны вне класса
    Только к названию класса нужно добавить Point:: (также как и у пространства имён)
*/

struct Point 
{
    float x, y;

    float norm();
    void normalize();
    Point operator+(const Point& right);
};


float Point::norm() 
{
    return sqrtf(x*x + y*y);
}

void Point::normalize() 
{
    float pnorm = norm();
    x /= pnorm;
    y /= pnorm;
}

Point Point::operator+(const Point& right) 
{
    Point result = {x + right.x, y + right.y};
    return result;
}

// operator<< это не метод, а просто функция
ostream& operator<<(ostream& left, const Point& right) 
{
    left << "(" << right.x << ", " << right.y << ")";
    return left;
}

int main() 
{
    Point a = {7.2, 3.1};
    Point b = {-4.6, 2.4};
    Point c = a + b;
    
    cout << c << endl;
    c.normalize();
    cout << c << endl;
}