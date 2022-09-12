/*
    Препроцессор, #define

    
    #define константы часто используются как размер массива.
    Так как для компилятора важно знать размер массива во время компиляции.

    Напоминание:

        Если задать размер массива значением, которое не известно на стадии компиляции вот так:

            int n;
            scanf("%i", &n);

            int a[n];

        то для компилятора работать с таким массивом будет намного сложнее.
        Поэтому некоторые компиляторы вообще не поддерживают такую возможность.
        На вашем компиляторе такой код может сработать, но на каком-то другом - нет.
        Поэтому писать так не стоит.
*/


#include <stdio.h>

#define SIZE 100


int main()
{
    int a[SIZE] = {0};


    for (int i = 0; i < SIZE; ++i)
        a[i] = 10 * i;


    for (int i = 0; i < SIZE; ++i)
        printf("%i ", a[i]);
    printf("\n");
}

