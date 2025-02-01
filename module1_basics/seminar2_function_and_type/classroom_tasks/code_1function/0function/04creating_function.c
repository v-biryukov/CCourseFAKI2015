/*
    Создание своих функций

    Давайте создадим свою функцию, которая будет принимать на вход число и возвращать квадрат этого числа. 
    Назовём эту функцию square. Сделать это можно так:


        int square(int x)
        {
            return x * x;
        }

    
    Объяснения синтаксиса создания функции:

        1)  square - это название, которое мы дали функции, используя его мы будем вызывать эту функцию позднее.

        2)  int x   в скобочках после названия функции - это тип и название объекта, который должна принимать функция.
            В данном случае функция будет принимать один объект типа int (то есть одно целое число).

        3)  int перед названием функции - это тип возвращаемого объекта.
            В данном случае функция будет возвращать целое число.

        4)  Тело функции - это то что содержится в фигурных скобках и исполняется при вызове функции.
            В данном случае тело функции состоит из одной строки:

                return x * x;

        5)  return это ключевое слово, которое мы используем, чтобы завершить функцию и указать значение, которое
            эта функция должна вернуть.
            В данном случае мы возвращаем выражение x * x, где x это то число, которое мы передали на вход функции.



    Выполнение программы всегда начинается с функции main, независимо от того сколько других функции ещё есть в программе.
    Например, в данной программе выполнение начнётся с функции main, а в функцию square программа может попасть только
    если функция square будет использована в функции main.



    Рассмотрим строку в функции main:

        printf("%i\n", square(5));

    когда программа дойдёт до этой строки она начнёт вычислять функцию square, передав её число 5.
    Программа зайдёт в функцию square и будет считать, в этой функции, что x равен 5.
    Затем программа дойдёт до строки

        return x * x;

    вычислит значение x * x, получит 25 и вернёт число 25 из функции square.


    После этого, она это число 25 подставит за место вызова функции, то есть она подставит 25 за место  square(5) и для программы 
    строка в функции main будет выглядеть так:

        printf("%i\n", 25);

*/


#include <stdio.h>

int square(int x)
{
    return x * x;
}

int main()
{
    printf("%i\n", square(5));
}


/*
    Задача:

        Что напечатает данная программа. Скомпилируйте эту программу, запустите и проверьте ваш ответ.
*/