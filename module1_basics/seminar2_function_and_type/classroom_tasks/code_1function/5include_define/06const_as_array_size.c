/*
    Константа как размер массива

    Обычные переменные в качестве размера массива мы использовать не можем так как они неизвестны во время компиляции.
    Но что насчёт константы в качестве размера массива?

    Дело в том, что константы тоже могут быть неизвестны на стадии компиляции.
    Слово const говорит, что эта переменная не может изменится после создания.
    Но при создании константы её можно задать любым значением, даже неизвестным во время компиляции.
    Поэтому в языке C для задания размера массива нужно использовать #define-константу или литерал.

    В языке C++ же, при создании константы, компилятор проверит правую часть выражения и, если справа стоит
    выражение, известное во время компиляции, то он пометит эту константу как известную во время компиляции.
    Эту константу можно будет использовать как размер массива.


    Программа из данного примера может сработать или нет в зависимости от компилятора.
*/


#include <stdio.h>


int main()
{
    int n;
    scanf("%i", &n);

    const int size = n;


    int a[size];

    for (int i = 0; i < size; ++i)
        a[i] = 10 * i;


    for (int i = 0; i < size; ++i)
        printf("%i ", a[i]);
    printf("\n");
}

