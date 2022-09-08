/*
    Числа типа float

    Числа типа float занимают в памяти 4 байта.
    Они могут хранить вещественные числа с точностью в 7 значащих десятичных цифр.
    Десятичная степень числа может принимать значения от -38 до 38.

*/

#include <stdio.h>

int main()
{
    printf("%i\n", sizeof(float));

    float a = 123.45678901234567890;
    printf("%.20f\n", a);


    float b = 1e-50;
    printf("%.60f\n", b);
}