/*
    Адрес переменной.

    На большинстве систем переменные типа int занимают 4 байта. Соответственно, если вы создадите 3 переменные типа int вот так:
    
    int a = 10;
    int b = 20;
    int c = 30;

    то в памяти это может выглядеть примерно вот так:

                |---------c---------|---------b---------|---------a---------|
        ═══╤════╤════╤════╤════╤════╤════╤════╤════╤════╤════╤════╤════╤════╗══════════
           │    │ 00 │ 00 │ 00 │ 30 │ 00 │ 00 │ 00 │ 20 │ 00 │ 00 │ 00 │ 10 │    
        ═══╧════╧════╧════╧════╧════╧════╧════╧════╧════╧════╧════╧════╧════╝══════════
                  ▲                   ▲                   ▲
                  |                   |                   |
                  &c                  &b                  &a


    Адрес переменной - это адрес первого байта того участка памяти, который занимает данная переменная.
    Чтобы получить адрес переменной в языке C нужно написать перед именем переменной значок &
    То есть, если у нас есть переменная:

        int a;

    То, чтобы найти её адрес нужно написать:

        &a

    
    Так как адрес - это номер ячейки в памяти, то по сути адрес это просто целое беззнаковое число.
    Какого размера должно быть это число? Размер этого числа должен быть такой, чтобы в него мог поместится номер любого байта.
    В современных системах размеры памяти обычно превышают 2^32 байт (4 Гигабайта), поэтому адреса хранятся в 64-х битных числах.


    Для печати адреса с помощью printf используется спецификатор %p
    В этом случае адрес напечатаются в 16-ричной системе счисления.
    Вообще с адресами гораздо более удобно работать в 16-ричной системе счисления и они так представляются почти всегда.

    Но так как адрес это по сути беззнаковое 64-х битное целое число, то можно использовать и спецификатор %llu
    В этом случае адрес напечатается в десятичной системе счисления. (при этом компилятор может выдать предупреждения)
*/

#include <stdio.h>


int main()
{
    int a = 10;
    int b = 20;
    int c = 30;

    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("%p\n", &c);


    printf("%llu\n", &a);
    printf("%llu\n", &b);
    printf("%llu\n", &c);
}


/*
    Задачи:

        1)  Создайте три переменные типа double.
            
            а)  Напечатайте адреса этих переменных в 16-ричной системе счисления с помощью спецификатора %p
            б)  Напечатайте адреса этих переменных в 10-тичной системе счисления с помощью спецификатора %llu

            Убедитесь, что переменные в памяти лежат в притык друг другу, то есть разница между их адресами равна 8 байт.



        2)  Создайте массив из чисел типа char, состоящий из 20-ти элементов.

            а)  Напечатайте адреса всех элементов этого массива в 16-ричной системе счисления с помощью спецификатора %p
            а)  Напечатайте адреса всех элементов этого массива в 10-тичной системе счисления с помощью спецификатора %llu

            Убедитесь, что переменные в памяти лежат в притык друг другу, то есть разница между их адресами равна 1 байт.


        Будут ли меняться адреса переменных при каждом запуске программы?
*/