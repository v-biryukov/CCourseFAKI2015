/*
    При возврате объекта из функции автоматически используется RVO или конструктор перемещения
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using std::cout, std::endl;

std::unique_ptr<int> getSquare(int x)
{
    return std::make_unique<int>(x * x);
}

int main()
{
    auto q = getSquare(9);
    cout << *q << endl;

    std::unique_ptr<int> p;
    p = getSquare(14);
    cout << *p << endl;
}
