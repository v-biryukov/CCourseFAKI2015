#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::cout;
using std::endl;


std::unique_ptr<int> getSquare(int x)
{
    return std::make_unique<int>(x * x);
}

// При возврате объекта из функции используется конструктор перемещения
// Так как возвращаемый объект -- rvalue, то используется конструктор перемещения
// И только если его нет, то тогда создаётся копия с помощью конструктора копирования


int main()
{
    // Следующий код сработает
    auto q = getSquare(9);
    cout << *q << endl;

    std::unique_ptr<int> p;
    p = getSquare(14);
    cout << *p << endl;
}
