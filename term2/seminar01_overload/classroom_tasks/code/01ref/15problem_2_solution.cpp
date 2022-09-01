#include <iostream>
using std::cout, std::endl;


/*
    Задача:

        Напишите функцию sumAndSave, которая должна принимать 3 аргумента
        Первые два аргумента по значению
        Третий аргумент по ссылке

        Функция должна складывать первые 2 аргумента и сохранять результат по третей ссылке

        Вызовите эту функцию из функции main

*/

void sumAndSave(int a, int b, int& c)
{
    c = a + b;
}


int main() 
{
    int x = 10, y = 20;
    int z;

    sumAndSave(x, y, z);
    cout << z << endl;


    sumAndSave(70, 80, z);
    cout << z << endl;
}

