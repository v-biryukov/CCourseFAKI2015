/*
    Прототип функции

    Представьте, что вы работает не с маленькой программой в которой есть 3 функции,
    а с большой программой в которой есть сотни или тысячи разных функций.
    Эти функции вызывают друг друга и может быть очень сложно расположить их в таком
    порядке, чтобы каждая функция "знала" все функции которые ей нужны.
    Более того, в процессе работы над программой вы можете изменять некоторые функции так, что они могут 
    начать вызывать функции, которые они не вызывали раньше, и порядок функций нужно будет постоянно менять.


    Чтобы не думать о порядке написания функций, можно просто сказать компилятору, что функция
    существует и её полное описание встретится дальше в программе.
    Для этого нужно написать прототип функции. 
    Прототип функции представляет собой просто первую строку функции с точкой с запятой на конце.

    Для функции is_prime прототип выглядит следующим образом:

        int is_prime(int number);

    Увидев это, компилятор поймёт, что функция is_prime, принимающая одно целое число типа int и возвращающая
    целое число типа int, написана где-то дальше в программе.
    Поэтому, если другая функция вызовет функцию is_prime с правильными аргументами, то компилятор не будет выдавать ошибку. 
*/


#include <stdio.h>


int is_prime(int number);


void print_primes(int a, int b)
{
    for (int i = a; i <= b; ++i)
    {
        if (is_prime(i))
            printf("%i ", i);
    }
    printf("\n");
}

int is_prime(int number)
{
    if (number < 2)
        return 0;

    for (int i = 2; i * i <= number; ++i)
    {
        if (number % i == 0)
            return 0;
    }
    
    return 1;
}

int main() 
{
    print_primes(100, 150);
}



/*
    Задачи:

        1)  В этой программе, благодаря прототипу, функция print_primes "знает" что существует 
            функция is_prime, принимающая одно целое число типа int и возвращающая тоже целое число типа int.

            Но что если в функции print_primes попытаться вызвать функцию is_prime, передав ей два целых числа типа int?
            Приведёт ли это к ошибке?
            Ведь с одной стороны функция print_primes "знает" что существует функция is_prime, но в то же время в прототипе
            указано, что функция is_prime должна принимать только одно целое число.


        2)  Напишите прототип для функции print_primes.
*/