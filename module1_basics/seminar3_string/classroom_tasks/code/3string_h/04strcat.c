/*
    Функция strcat
    
    char* strcat (char a[], const char b[]))  -  Добавляет копию строки b в конец строки a. Аналог a += b.


    char a[20] = "Mouse";
    char b[20] = "Elephant";

    Строки это массивы, поэтому их нельзя просто добавить друг к другу

        a += b;  // Не работает

    Это не будет работать! Нужно использовать strcat:

        strcat(a, b);


    К сожалению функция strcat не является удачной функцией. У неё есть 2 серьёзные проблемы:

        1)  Также как и функция strcpy, она может выйти за пределы массива, в который записывает,
            если строка будет слишком большой.

        2)  Функции на вход передаются 2 указателя на начала двух строк. Но записывает эта функция в конец первой строки.
            Это значит, что функция должна найти конец первой строки, а для этого она должна пройти по всей первой
            строке до нулевого символа. И, если строка большая, то это может быть долго.
            Таким образом функция strcat не очень эффективна если первая строка длинная.
*/



#include <stdio.h>
#include <string.h>

int main() 
{
    char a[20] = "Mouse";
    char b[20] = "Elephant";

    printf("a = %s, b = %s\n", a, b);

    strcat(a, b);

    printf("a = %s, b = %s\n", a, b);
}
