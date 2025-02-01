#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

/*
    Переменную errno можно сравнить с кодами ошибок, таких как:
        ENOMEM - не может выделить необходимое количество памяти
        EDOM   - аргумент математической функции не входит в её область определения
        ENOENT - файл не существует
        и многие другие
*/


int main()
{
    // Выделяем больше чем можем себе позволить
    int* p = (int*)malloc(10000000000000);

    if (errno == ENOMEM)
    {
        printf("Malloc. Not enought memory!\n");
    }


    double a = log(-1);
    if (errno == EDOM)
    {
        printf("log argument should be positive!\n");
    }
}