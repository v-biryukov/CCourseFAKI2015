/*
    Числа типа int


    Числа типа int на большинстве системах занимают в памяти размер в 4 байта = 32 бита.
    1 бит в памяти компьютера хранится каким-то образом. Например, в виде напряжения на одном из транзисторов/конденсаторов.
    Каждый бит может принимать 2 значения: 0 или 1. Например, 0 - это низкое напряжение на соответствующем транзисторе, а 1 - высокое.

    
    Если 1 бит может принимать 2 значения, то последовательность из 32 бит может принимать  2^32  значений (то есть 2 в степени 32). 
    2^32 = 4294967296, следовательно числа типа int могут принимать 4294967296 различных значений.
    Так как числа типа int хранят и положительные и отрицательные числа и ноль, то диапазон значений, которые может хранить int:

        от -2147483648 до 2147483647


    Следует отметить, что числа типа int занимают 4 байта на большинстве системах, но на некоторых системах такие
    числа могут иметь другой размер (например 2 байта или 8 байт). 
    Соответственно, в этом случае изменится и диапазон принимаемых значений.
    Чтобы узнать, какой размер чисел типа int на вашей системе, можно использовать:

        -   sizeof - возращает размер типа в байтах
        -   константы INT_MIN и INT_MAX из библиотеки limits.h - 
            возвращают минимальное и максимальное значения, которые могут принимать числа типа int.

*/

#include <stdio.h>
#include <limits.h>

int main()
{
    int a = 10;

    printf("%i\n", sizeof(int));
    printf("%i\n", sizeof(a));

    printf("%i\n", INT_MIN);
    printf("%i\n", INT_MAX);
}



/*
    Задача:

        Скомпилируйте программу, запустите и выясните какой размер чисел типа int на вашей системе.
        
        Для компиляции:

            gcc 00int.c

        Для запуска:

            ./a.out   (Linux)          a.exe   (Windows)

*/