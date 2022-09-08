/*
    Значения inf и nan

    В типах целых чисел могут хранится только целые числа.
    Но числа с плавающей точкой, помимо хранения вещественных чисел, могут ещё хранить в себе особые значения.
    А именно бесконечность (inf) и особое значение 'не число' ('not a number' - nan).

    1)  Бесконечность (inf)

        Если мы делим целое число на целое число, равное нулю, например вот так:

            1 / 0

        То это грубая ошибка, являющаяся неопределённым поведением.


        Если же мы делим вещественное число на вещественное число, равное нулю:

            1.0 / 0.0

        То согласно стандарту IEEE 754, описывающему формат представления чисел с плавающей точкой,
        такое вычисление является корректным и его результатом будет специальное значение inf



    2)  Не число - Not a Number (nan)

        Значение nan записывается в число если проводится какая-нибудь недопустимая операция над вещественными числами.
        Например: деление ноль на ноль, корень из отрицательного числа, арсинус от двух и так далее.

*/

#include <stdio.h>

int main()
{
    float a = 1.0 / 0.0;
    printf("%f\n", a);


    float b = 0.0 / 0.0;
    printf("%f\n", b);
}


/*
    Задачи:

        1)  Чему будет равен результат умножения бесконечности на значение 'Not a Number'?

        2)  Создайте переменную типа float и запишите в неё значение 'минус бесконечность'.

        3)  Чему будет равен результат сложения бесконечности с минус бесконечностью?
*/