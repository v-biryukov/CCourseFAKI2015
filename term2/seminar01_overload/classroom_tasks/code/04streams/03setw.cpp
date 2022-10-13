/*
    Печать чисел с фиксированной шириной и с замощением другими символами.

    Модификатор std::setw(n) - при печати числа, будет печататься минимум n символов.
    Недостающие символы будут замещаться пробелами.
    cout << std::setw(5) << a << endl;     это аналог     printf("%5i\n", a);

    Модификатор std::setfill(c) - замещает недостающие символы символом c.
    cout << std::setw(5) << std::setfill('0') << a << endl;     это аналог     printf("%05i\n", a);
*/


#include <iostream>
#include <iomanip>
using std::cout, std::endl;

int main()
{
    int a = 123;

    cout << std::setw(5) << a << endl;
    cout << std::setw(5) << std::setfill('0') << a << endl;
}