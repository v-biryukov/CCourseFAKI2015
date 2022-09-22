/*
    Задача:

        Напишите шаблонную функцию T sum(T* arr, size_t size), которая возвращает сумму массива переменных.
        Какие условия на пользовательский тип объекта будут накладываться в этой шаблонной функции?

        В этой задаче вам понадобиться value initialization из прошлого семинара.
*/

#include <iostream>
#include <string>
#include "complex.h"
using std::cout, std::endl;




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
