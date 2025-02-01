/*
    Адреса переменных в разных функциях.

    Одна из самых важных вещей, которые вы должны помнить о функциях это то, что если мы передаём какой-либо
    объект внутрь функции, то этот объект копируется (из этого правила есть исключение - массивы).

    Например, если у нас есть переменная типа int и мы передаём её в функцию, то при передаче в функцию она копируется,
    и функция работает с копией этой переменной. 

    В этом примере мы убедимся, что переменная a из функции main и переменная a из функции func это разные объекты.
    Для этого просто печатаем адрес обеих переменных и видим, что они отличаются.
*/

#include <stdio.h>


void func(int a)
{
    printf("a in func: %p\n", &a);
}

int main()
{
    int a = 10;
    printf("a in main: %p\n", &a);

    func(a);
}


/*
    Задача:

        Скомпилируйте программу и запустите.
        Убедитесь, что переменная a из функции main и переменная a из функции func хранятся в разных местах в памяти.
*/