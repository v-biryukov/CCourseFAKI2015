/*
    Перемещение переменной типа int

    Задача:

        У нас есть две переменные типа int и мы перемещаем одну переменную в другую.
        Чему будут равну переменные a и b после перемещения?
*/


#include <iostream>
#include <utility>
using std::cout, std::endl;

int main()
{
    int a = 100;
    int b = 200;

    cout << a << " " << b << endl;

    b = std::move(a);   
}