/*
    Задача:

        У нас есть переменные a и p типов int и int* соответсвенно. p хранит адрес a.

        Если мы создадим переменную q типа int* и напишем так:

            int* q = p;

        То адрес какой переменной будет хранить q: адрес переменной a или адрес переменной p?
        Проверьте себя, напечатав переменную q на экран.
*/



#include <stdio.h>


int main()
{
    int a = 10;
    int* p = &a;

    printf("a = %i\n", a);
    printf("p = %p\n", p);

    printf("address of a = %p\n", &a);
    printf("address of p = %p\n", &p);




    int* q = p;

}

