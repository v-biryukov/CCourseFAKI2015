/*
    Решения:

        1)  Выражение  a * 2  вычисляется так как есть перегруженный оператор a.operator*(2)
            Выражение  2 * a  даёт ошибку так как не было перегруженного оператора operator*(2, a)

            Но его можно просто написать, как это сделано ниже.

            Сделать этот оператор методом мы не можем, так как перегруженный оператор может быть методом
            только первого аргумента, первый аргумент в данном случае это число целочисленного типа float.
            Добавить метод в тип float мы не можем, так как float это вообще не класс.

            Замечание: Литерал 2 на самом деле имеет тип int, но int может конвертироваться во float если нужно 


        2)  Можно ли сделать перегруженный оператор << методом класса Point?

            Нет, нельзя. Перегруженный оператор может быть методом только первого аргумента.
*/

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

Point operator*(float k, Point a)
{
    return a * k;
}


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





