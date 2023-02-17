/*
    В прошлом семестре, для хранения результатов логических операций, мы использовали целочисленные типы (например int).
    
    В языке C++ есть встроенный тип bool, который может принимать 2 значения (true и false).
    Для хранения значения логических переменных желательно использовать этот тип

    
    При печати на экран с помощью std::cout переменных типа bool печатается либо 0 либо 1
    Чтобы на экран печаталось false или true нужно в std::cout передать специальный объект std::boolalpha 

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
    cout << std::boolalpha << c << endl;
}


