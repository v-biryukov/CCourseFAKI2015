#include <stdio.h>


int main()
{
    int a = 10;

    int b = exchange(&a, 20);

    printf("%i %i\n", a, b);
}


/*
    Задача:

        Напишите функцию exchange, которая будет принимать указатель на число типа int и число типа int:

            int exchange(int* pvalue, int new_value)

        Эта функция должна записывать значение new_value по адресу pvalue и возвращать старое значение, 
        которое хранилось по адресу pvalue.

        То есть данная программа должна напечатать:

            20 10
*/