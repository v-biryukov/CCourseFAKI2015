/*
    Обратите внимание на следующие моменты в этом решении:

    1)  При переносе функций внутрь класса у них стало на 1 аргумент меньше
        Просто потому что все методы неявно принимают вызывающий их объект

        Например, если a это точка, то при вызове:
            a.norm()
        
        метод norm 'знает', что его вызвала имено точка a и может доступаться до её полей x и y


    2)  Перегруженные операторы тоже могут быть методами
        При этом оператор преобразуется следующим образом:

        a @ b   ->   a.operator@(b)
        где на месте @ может быть любой бинарный оператор

        Например, сложение преобразуется так:
        a + b   ->   a.operator+(b)

        Обратите внимание, что перегруженный оператор может стать методом только первого аргумента


    3)  Перегрузка оператора << для типов std::ostream и Point
        Для более удобного вывода на экран можно перегрузить этот оператор

        Когда компилятор встретит выражение     cout << a    где cout имеет тип std::ostream, а имеет тип Point
        то он вызовет эту функцию.
        Эта функция должна вызывать ссылку на cout так как результатом   cout << a   тоже должен быть cout
        чтобы мы могли выводить цепочкой, например так:   cout << a << b << endl
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
};

std::ostream& operator<<(std::ostream& out, Point a)
{
    out << std::setprecision(2) << "(" << a.x << ", " << a.y << ")";
    return out;
}




int main() 
{
    Point a = {7.2, 3.1};
    Point b = {-4.6, 2.4};
    
    cout << a << endl;
    cout << b << endl;

    Point c = a + b;
    cout << c << endl;

    cout << c * 1.5f << endl;

    c.normalize();
    cout << c << endl;
}




