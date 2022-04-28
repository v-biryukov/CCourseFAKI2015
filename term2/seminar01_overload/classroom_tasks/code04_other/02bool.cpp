#include <iostream>
using std::cout, std::endl;

/*
    В прошлом семестре, для хранения результатов логических операций, 
    мы использовали целочисленные типы.
    В языке C++ есть встроенный тип bool, который 
    может принимать 2 значения (true и false).
*/

int main() 
{
    bool a = true;
    bool b = false;

    bool c = a || b;

    if (c)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}