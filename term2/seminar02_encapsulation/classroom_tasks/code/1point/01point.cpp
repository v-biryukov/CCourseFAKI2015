/*
    Это программа на языке C++, для компиляции:
        g++ 01point.cpp

    Та же самая точка, но на языке C++

    В этом файле была видоизменена программа из предыдущего файла.
    Были использованы перегруженные операторы для более удобного сложения и умножения точек.
    Также была использована ссылка вместо указателя в функции pointNormalize.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout, std::endl;


struct Point 
{
    float x, y;
};

void pointPrint(Point a)
{
    cout << std::setprecision(2) << "(" << a.x << ", " << a.y << ")" << endl;
}

Point operator+(Point a, Point b)
{
    Point result = {a.x + b.x, a.y + b.y};
    return result;
}

float pointNorm(Point a)
{
    return std::sqrt(a.x * a.x + a.y * a.y);
}

Point operator*(Point a, float k)
{
    Point result = {k * a.x, k * a.y};
    return result;
}

void pointNormalize(Point& a)
{
    float norm = pointNorm(a);
    a.x /= norm;
    a.y /= norm;
}




int main() 
{
    Point a = {7.2, 3.1};
    Point b = {-4.6, 2.4};
    
    pointPrint(a);
    pointPrint(b);

    Point c = a + b;
    pointPrint(c);

    pointPrint(c * 1.5f);

    pointNormalize(c);
    pointPrint(c);
}




/*
    Задача:

        1)  Инкапсулируйте функции operator+, pointNorm, operator* и pointNormalize
            Их нужно сделать методами, то есть положить внутрь структуры Point
            Не забудьте сделать соответствующие методы константными

        2)  Можно сделать то же самое с функцией printPoint, а можно поступить по-другому
            и перегрузить оператор << для типов std::ostream и Point
*/