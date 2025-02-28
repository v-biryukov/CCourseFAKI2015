#include <stdio.h>


void mult(int a)
{
    a *= 2;
}


int main()
{
    int a = 10;
    mult(a);

    printf("%i\n", a);
}


/*
    Решение:

        Это программа напечатает на экран число 10.

        Разберёмся подробней, что происходит в данной программе:


            1)  Заходим в функцию main, так как любая программа начинается с функции main.

            2)  Создаём переменную a, равную 10.

            3)  Вызываем функцию mult и передаём в эту функцию a.

            4)  Переменная a из функции main копируется в переменную a функции mult.

            5)  Внутри функции mult мы увеличиваем переменную a функции mult в 2 раза.
                При этом переменная a из функции main не меняется.

            6)  Выходим из функции mult.

            7)  Печатаем на экран значение переменной a функции main, то есть число 10.


        Получается функция mult абсолютно бесполезна.
        Да, это так, в данном примере эта функция используется для обучающих целей.
*/