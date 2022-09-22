#include <stdio.h>
#include <ctype.h>

int main() 
{
    char str[200];

    for (int i = 0; 1; ++i) 
    {
        char x;
        scanf("%c", &x);

        if (isspace(x)) 
        {
            str[i] = '\0';
            break;
        }
        
        str[i] = x;
    }


    printf("%s\n", str);
}


/*
    Задача:

        Пусть у нас есть массив str из 200 элементов типа char. Вам нужно считать с экрана строку в этот массив.
        Считывайте посимвольно с помощью функции scanf со спецификатором %c.
        Остановится нужно когда достигните пробельного символа. 
        К пробельным символам относятся пробел(' '), символ табуляции('\t') и символ переноса строки('\n').

        Известно, что длина входящей строки будет меньше, чем 200 символов.
*/