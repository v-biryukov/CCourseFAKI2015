#include <stdio.h>
#include <stdlib.h>

/*
    Другим вариантом обработки ошибок в языке C являются коды возврата
    В этом случае функция возвращает специальное значение, если произошла ошибка

    В языке C, самый известным примером такого варианта обработки ошибок является malloc
    malloc возвращает NULL, если выделить память не получилось

    Аналогично работает функция открытия файла fopen и многие другие функции
*/


int main()
{
    void* p = malloc(100000000000000);
    if (p == NULL)
    {
        printf("Error: cannot allocate enough memory.\n");
    }
    

    FILE* fp = fopen("file_doesnt_exist.txt", "r");
    if (fp == NULL)
    {
        printf("Cannot open file.\n");
    }


    free(p);
    fclose(fp);
}