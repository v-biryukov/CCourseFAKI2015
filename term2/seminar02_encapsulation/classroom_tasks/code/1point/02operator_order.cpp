#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout, std::endl;


struct Point 
{
    float x, y;

    Point operator*(float k) const
    {
        Point result = {k * x, k * y};
        return result;
    }

};

std::ostream& operator<<(std::ostream& out, Point a)
{
    out << std::setprecision(2) << "(" << a.x << ", " << a.y << ")";
    return out;
}


int main() 
{
    Point a = {2.1, 1.5};
    
    cout << a * 2 << endl;
    cout << 2 * a << endl;
}



/*
    Задачи:

        1)  В этой программе выражение  a * 2  вычисляется правильно, но
                             выражение  2 * a  даёт ошибку.

            Из-за чего это происходит? Исправьте ситуацию так, чтобы выражение 2 * a также вычислялось.


        2)  Можно ли сделать перегруженный оператор << методом класса Point?
*/


