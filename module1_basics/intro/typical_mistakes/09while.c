/*
    Данная простая программа должна была просто печатать на экран все целые числа от 1 до 10.

    Но почему-то программа просто зависает и ничего не делает.
    В чём ошибка?

    Чтобы завершить работу программы можно использовать комбинацию клавиш  Ctrl-C
*/

#include <stdio.h>

int main()
{
    int i = 1;

    while (i <= 10);
    {
        printf("%i ", i);
        i += 1;
    }

    printf("\n");
}