/*
    Классы и перегрузка операторов

    Написан простейший класс - точка, а также функции для работы с ним.
    Были использованы перегруженные операторы для более удобного сложения и умножения точек.

    Задача 1:

        Инкапсулируйте функции operator+, pointNorm, operator*, pointNormalize и pointPrint.
        Их нужно сделать методами, то есть положить внутрь структуры Point.
        Не забудьте сделать соответствующие методы константными.

        Можно ли инкапсулировать функцию Point operator*(float k, Point a) ?


    Задача 2:

        Удалите метод pointPrint и замените его перегруженным оператором << с объектом типа std::ostream.
        Чтобы точку можно было выводить на экран, используя std::cout.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout, std::endl;


class Point 
{
public:
    float x;
    float y;
};

void pointPrint(Point a)
{
    cout << "(" << a.x << ", " << a.y << ")" << endl;
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

Point operator*(float k, Point a)
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

    pointPrint(5 * c);
    pointPrint(c * 2);

    pointNormalize(c);
    pointPrint(c);
}