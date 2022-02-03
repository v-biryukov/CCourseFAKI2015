#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

/*
    Обработка ошибок с помощью глобальной переменной errno - 
    это один из основных способов обработки ошибов в языке C

    После функции, в которой происходит ошибка, в глобальную
    целочисленную переменную errno записывается код ошибки.
*/


int main()
{
    printf("No Error. Errno = %d\n", errno);

    // Неправильная работа с математическими функциями
    double x = sqrt(-1);
    printf("Sqrt(-1). Errno = %d\n", errno);

    // Выделяем больше чем можем себе позволить
    int* p = (int*)malloc(10000000000000);
    printf("Malloc. Errno = %d\n", errno);

    // Пытаемся открыть файл, который не существует
    FILE* f1 = fopen("abc.txt", "r");
    printf("Opening non existed file. Errno = %d\n", errno);

    // Неправильный режим открытия файла (z)
    FILE* f2 = fopen("non_existed_file.txt", "z");
    printf("Wrong file mode. Errno = %d\n", errno);
}