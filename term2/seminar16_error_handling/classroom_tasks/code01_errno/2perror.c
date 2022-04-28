#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
    Для удобства в языке C существует функция perror, которая
    сама проверяет переменную errno и печатает соответствующее
    сообщение
*/


int main()
{
    perror("Message");

    // Неправильная работа с математическими функциями
    float x = sqrt(-1);
    perror("Message");

    // Выделяем больше чем можем себе позволить
    int* p = (int*)malloc(10000000000000);
    perror("Message");

    // Пытаемся открыть файл, который не существует
    FILE* f1 = fopen("non_existed_file.txt", "r");
    perror("Message");

    // Неправильный режим открытия файла (z)
    FILE* f2 = fopen("abc.txt", "z");
    perror("Message");
}