/*
    Препроцессор, #define

    Ещё одна известная директива препроцессора это директива #define.
    
    Директива #define занимается текстовыми подстановками в программе. 
    В простейшем варианте она просто заменяет один текст на другой.

    Например:

        #define GREETING "Hello, friend!\n"

    означает, что программа пройдёт по всему тексту данного файла и подставит заместо
    иденитификаторов GREETING строку "Hello, friend!\n".

    
    Как правило такие define-константы пишутся в верхнем регистре чтобы избежать ошибок когда define заменял бы
    что-то, что он не должен был бы заменять.


*/


#include <stdio.h>

#define GREETING "Hello, friend!\n"


int main()
{
    printf(GREETING);
}


/*
    Задача:

        Создайте define-константу, которое будет заменять VALUE на число 123456.
        Напечатайте это число как:

            printf("%i\n", VALUE);
*/