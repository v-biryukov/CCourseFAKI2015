/*
    Тип bool

    В языке C, для хранения результатов логических операций, допускается использование переменных 
    целочисленных типов (например int-ов).
    
    В языке C++ лучше в этом случае использовать встроенный тип bool, который может принимать 2 значения 
    (true и false).

    При печати на экран с помощью std::cout переменных типа bool печатается либо 0 либо 1.
    Чтобы на экран печаталось false или true нужно в std::cout передать специальный объект std::boolalpha.
*/

#include <iostream>
using std::cout, std::endl;


bool isEven(int a)
{
    return a % 2 == 0;
}

int main() 
{
    bool a = isEven(10);
    bool b = isEven(15);
    bool c = a || b;


    if (c)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;


    cout << c << endl;

    cout << std::boolalpha;
    cout << c << endl;
}