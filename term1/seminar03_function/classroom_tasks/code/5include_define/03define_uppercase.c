/*
    Препроцессор, #define

    Как правило такие define-константы пишутся в верхнем регистре чтобы избежать ошибок когда define заменял бы
    что-то, что он не должен был бы заменять, например, названия переменных, функций и т. д.


*/


#include <stdio.h>

#define value 123456


int main()
{
    printf("%i\n", value);

    // ...

    int value = 10;
}


/*
    Задачи:

        1)  В данной программе происходит ошибка. Почему?

        2)  Если заменить строку

                int value = 10;

            на

                int value2 = 10;

            то останется ли ошибка? То есть будет ли заменяться value2 на 1234562?

*/