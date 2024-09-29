/*
    Более правильное решение - это считать все символы из стандартного входа до символа переноса строки.
    Это можно сделать с помощью если просто в цикле считывать символы пока не наткнёся на символ '\n'.
*/


#include <stdio.h>

int main()
{
    int a;
    scanf("%i", &a);
    printf("a = %i\n", a);


    while (1)
    {
        char c;
        scanf("%c", &c);

        if (c == '\n')
        {
            break;
        }
    }


    char str[100];
    scanf("%[^\n]", str);
    printf("str = %s\n", str);
}
