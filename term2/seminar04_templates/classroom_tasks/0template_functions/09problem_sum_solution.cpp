/*
    Условия, которые накладываются на пользовательский класс T:

        1)  Конструктор по умолчанию. Используется тут:

            T result {};

        2)  Перегруженный оператор+=  Используется тут:

            result += arr[i];


        3)  Конструктор копирования. Может использоваться при возврате объекта из функции


*/

#include <iostream>
#include <string>
#include "complex.h"
using std::cout, std::endl;


template <typename T>
T sum(T* arr, size_t size)
{
    T result {};

    for (size_t i = 0; i < size; ++i)
        result += arr[i];

    return result;
}


int main() 
{
    int a[5] = {10, 20, 30, 40, 50};
    cout << sum(a, 5) << endl; 

    float b[5] = {4.1, 1.5, 6.0, -1.7, 0.4};
    cout << sum(b, 5) << endl; 


    std::string c[5] {"Cat", "Dog", "Mouse", "Ant", "Elephant"};
    cout << sum(c, 5) << endl; 

    Complex d[5] {{1.0, 6.0}, {-1.5, 1.2}, {2.0, 2.0}, {-5.4, 9.5}, {4.1, -7.1}};
    cout << sum(d, 5) << endl; 
}
