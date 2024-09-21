/*
    Оператор new

    В языке C для выделения памяти в куче использовалась функции malloc и free.
    В языке C++ аналогом этих функций является операторы new и delete.

    Для скалярных типов оператор new делает то же самое, что и malloc.
*/

#include <iostream>
#include <cstdlib>
#include <string>
using std::cout, std::endl;


int main()
{
    // Выделим 1 int в куче и освободим его
    int* p = (int*)malloc(1000000 * sizeof(int)); // Ok

    p[5] = 123;

    free(p);



    // Выделим 1 int в куче и освободим его
    int* pb = new int;

    delete pb;



    // Выделим 100 int-ов в куче и освободим их
    int* pc = (int*)malloc(100 * sizeof(int));

    free(pc);



    // Выделим 100 int-ов в куче и освободим их
    int* pd = new int[100];

    delete [] pd;
}