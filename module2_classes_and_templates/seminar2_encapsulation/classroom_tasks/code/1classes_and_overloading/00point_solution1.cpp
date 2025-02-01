/*
    Обратите внимание на следующие моменты в этом решении:

    1)  При переносе функций внутрь класса у них стало на 1 аргумент меньше.
        Просто потому что все методы неявно принимают вызывающий их объект.

        Например, если a это точка, то при вызове:

            a.norm()
        
        метод norm 'знает', что его вызвала имено точка a и может доступаться до её полей x и y.


    2)  Перегруженные операторы тоже могут быть методами. При этом оператор преобразуется следующим образом:

            a @ b   ->   a.operator@(b)

        где на месте @ может быть любой бинарный оператор. Например, сложение преобразуется так:

            a + b   ->   a.operator+(b)

        Обратите внимание, что перегруженный оператор может стать методом только первого аргумента.

    
    3)  Инкапсулировать функцию Point operator*(float k, Point a) нельзя.
        Инкапсулировать можно только такие операторы, у которых первый аргумент является объектом типа
        нашего класса (или ссылкой на объект нашего класса).
        Тут ничего нельзя поделать, эта функция так и не станет методом.

*/

#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout, std::endl;


struct Point 
{
    float x, y;

    Point operator+(Point b) const
    {
        Point result = {x + b.x, y + b.y};
        return result;
    }

    float norm() const
    {
        return std::sqrt(x * x + y * y);
    }

    Point operator*(float k) const
    {
        Point result = {k * x, k * y};
        return result;
    }

    void normalize()
    {
        float normv = norm();
        x /= normv;
        y /= normv;
    }

    void print() const
    {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};


Point operator*(float k, Point a)
{
    return a * k;
}


int main() 
{
    Point a = {7.2, 3.1};
    Point b = {-4.6, 2.4};
    
    a.print();
    b.print();

    Point c = a + b;
    c.print();

    Point d = 5 * c;
    d.print();

    d = c * 2;
    d.print();


    c.normalize();
    c.print();


    a + b

}







