/*
    Методы front и back

    Можно быстро получить первый и последний элементы вектора, используя методы front и back.
    Конечно, то же самое можно сделать и с помощью квадратных скобочек, но использование
    методов front и back делает код более читаемым.
*/

#include <iostream>
#include <vector>
#include <string>
using std::cout, std::endl;

int main()
{
    std::vector<int> v {10, 20, 30, 40, 50};

    cout << v[0] << endl;
    cout << v[v.size() - 1] << endl;

    cout << v.front() << endl;
    cout << v.back() << endl;
}