/*
    В предыдущем примере есть по крайней мере 3 недостатка:

        1)  Размер объекта типа int не обязательно равен 4 байта. Этот размер зависит от системы и
            на разных системах может принимать другие значения, например, 2 или 8 байт.
            Чтобы наш код работал на всех системах выделять память под один int нужно так:

                malloc(sizeof(int));


        2)  Функция malloc возвращает указатель типа void*, а тип указателя p это int*.
            То есть, если мы напишем так:

                int* p = malloc(sizeof(int));

            То тут будет происходить неявное приведение типа void* к типу int*. Неявное приведение указателей нужно избегать.
            В языке C такое приведение сработает, но в языке C++ это будет ошибкой, так как язык C++ строже относится 
            к приведению типов указателей. В данном случае лучше явно приводить тип указателя от void* к int* вот так:

                int* p = (int*)malloc(sizeof(int));


        3)  У функции malloc может не получится выделить необходимую память.
            Если у malloc не получится выделить запрошенное количество памяти по причине нехватки памяти
            или по какой-либо другой причине, то функция malloc вернёт нулевой указатель (то есть указатель, равный NULL).
            Поэтому, желательно всегда проверять этот указатель на равенство NULL и, если он равен NULL, обрабатывать ошибку.
            В примерах эта проверка часто будет опускаться, чтобы не захламлять код
            Но при написании серьёзных программ эту проверку всегда нужно делать.
*/

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int* p = (int*)malloc(sizeof(int));

    if (p == NULL)
    {
        printf("Error. Can't allocate memory!\n");
        exit(1);
    }

    *p = 123;
    printf("%i\n", *p);

    free(p);
}


/* 

    Задача:

        Создайте в куче один объект типа double и присвойте ему число 12.34.
*/