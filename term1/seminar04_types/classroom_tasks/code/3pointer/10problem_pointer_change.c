/*
    Задача:

        У нас есть 3 переменные типа int, равные нулю. 
        Также у нас есть один указатель типа int*, равный адресу одной из переменных.

        Вам нужно, используя этот один указатель, изменить значения трёх переменных так,
        чтобы они приняли значения 10, 20 и 30 соответственно.

        Создавать новые указатели нельзя.
        Изменять переменные можно только через указатель.
        Но можно присваивать указателю адреса других переменных.
        Код можно писать только между двумя коментариями.
*/


#include <stdio.h>


int main()
{
    int a = 0;
    int b = 0;
    int c = 0;

    int* p = &a;

    // Пишите ваш код ниже





    // ||||||||||||||||||||

    printf("%i %i %i\n", a, b, c);
}

