/*
    Инициализация глобальных переменных

    Инициализация глобальных переменных очень похожа на инициализацию обычных переменных на стеке.
    Объекты можно инициализировать также, используя круглые или фигурные скобки.

    Единственное отличие - глобальные переменные всегда инициализируются.
    Даже при default-инициализации глобальные скалярные переменные инициализируются нулями.
*/

#include <iostream>
#include <string>
using std::cout, std::endl;

int a[20];  //  инициализуруется нулями


int main()
{
    int b[20];  // не инициализируется


    for (int i = 0; i < 20; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;


    for (int i = 0; i < 20; ++i)
    {
        cout << b[i] << " ";
    }
    cout << endl;
}