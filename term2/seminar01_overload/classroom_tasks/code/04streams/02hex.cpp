/*
    Печать чисел в шестнадцатеричном виде

    Поведение объекта std::cout можно менять с помощью модификаторов.
    Для печати на экран целого числа в шестнадцатеричной системе счисления можно использовать std::hex.
    Для восьмеричной - std::oct. Для десятичной - std::dec. 
*/


#include <iostream>
using std::cout, std::endl;

int main()
{
    int a = 12345;

    cout << std::dec << a << endl;
    cout << std::oct << a << endl;
    cout << std::hex << a << endl;
}