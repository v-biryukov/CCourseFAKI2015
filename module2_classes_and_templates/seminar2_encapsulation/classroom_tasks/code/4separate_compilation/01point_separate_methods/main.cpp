/*
    Вынос определений методов вне класса.

    Методы внутри класса можно только объявить, а определить их можно вне класса.
    Например, метод norm объявлен внутри класса:

        float norm() const;

    а определён вне класса:

        float Point::norm() const
        {
            return std::sqrt(x * x + y * y);
        }


    Чтобы компилятор понимал к какому классу относится тот или иной метод,
    к его имени вне класса нужно добавить название класса и два двоеточия.
    Поэтому метод norm вне класса Point называется как Point::norm.

*/


#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout, std::endl;


struct Point 
{
    float x, y;

    Point operator+(Point b) const;
    float norm() const;
    Point operator*(float k) const;
    void normalize();
};


Point Point::operator+(Point b) const
{
    Point result = {x + b.x, y + b.y};
    return result;
}

float Point::norm() const
{
    return std::sqrt(x * x + y * y);
}

Point Point::operator*(float k) const
{
    Point result = {k * x, k * y};
    return result;
}

void Point::normalize()
{
    float normv = norm();
    x /= normv;
    y /= normv;
}


std::ostream& operator<<(std::ostream& out, Point a)
{
    out << std::setprecision(2) << "(" << a.x << ", " << a.y << ")";
    return out;
}


int main() 
{
    Point a = {7.2, 3.1};
    cout << a.norm() << endl;
}




