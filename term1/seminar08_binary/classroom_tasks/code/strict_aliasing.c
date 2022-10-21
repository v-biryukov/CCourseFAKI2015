#include <stdio.h>

int func(int* p, float* q)
{
    *p = 10;
    *q = 0;

    int temp = *p;
    printf("%i\n", temp);
    return temp;
}

int main()
{
    int a = 20;

    printf("%i\n", func(&a, (float*)&a));
}


/*
    Задачи:

        1)  Что напечатает данная программа:

            Если скомпилировать так:

                gcc strict_aliasing.c

            Или так:

                gcc -O3 strict_aliasing.c

            Или так:

                gcc -O3 -fno-strict-aliasing strict_aliasing.c


        2)  Будет ли наблюдаться такое поведение, если заменить тип float в этой программе на следующие типы:

            -   double
            -   long long
            -   unsigned int
            -   char

*/