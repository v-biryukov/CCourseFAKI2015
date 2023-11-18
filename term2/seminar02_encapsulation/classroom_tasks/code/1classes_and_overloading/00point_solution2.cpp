/*
    Перегрузка оператора << для типов std::ostream и Point.
    Для более удобного вывода на экран можно перегрузить этот оператор.

    Когда компилятор встретит выражение  cout << q  где cout имеет тип std::ostream, а q имеет тип Point,
    то он вызовет эту функцию. Эта функция должна возвращать ссылку на cout так как результатом
    cout << a  тоже должен быть cout, чтобы мы могли выводить цепочкой, например так:  cout << a << b << endl.
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

Point operator*(float k, Point a)
{
    return a * k;
}

std::ostream& operator<<(std::ostream& out, Point a)
{
    out << "(" << a.x << ", " << a.y << ")";
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

    cout << 5 * c << endl;
    cout << c * 2 << endl;

    c.normalize();
    cout << c << endl;
}




