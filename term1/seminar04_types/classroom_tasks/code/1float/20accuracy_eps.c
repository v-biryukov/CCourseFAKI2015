#include <stdio.h>

int main()
{
    double a = 3 * 0.1;
    double b = 0.3;

    if (a == b)
        printf("Yes\n");
    else
        printf("No\n");
}

/*
    Задача:

        Понятно, что сравнивать числа типа float и double с абсолютной точностью с помощью оператора == это не самая лучшая идея.
        Но как тогда сравнивать эти числа. Допустим у нас есть числа a и b и мы хотим их сравнить, как это сделать?

        Числа этих типов всегда сравниваются с некоторой погрешностью.
        То есть берётся какое-нибудь маленькое число eps, например eps 10^(-15).
        Число a считается равным числу b, если оно входит в интервал  (b - eps, b + eps).

        Измените программу так, чтобы числа a и b проверялись на равенство с точностью eps = 1e-15.
*/