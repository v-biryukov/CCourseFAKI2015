/*
    Чтение данных из бинарного файла

    Пример чтения массива чисел типа float из бинарного файла.
*/

#include <stdio.h>


int main()
{
    float a[3];


    FILE* f = fopen("fnumbers.bin", "rb");

    fread(&a, sizeof(int), 3, f);
    fclose(f);


    for (size_t i = 0; i < 3; ++i)
    {
        printf("%f\n", a[i]);
    }


    
}



/*
    Задача:

        Запустите программу.
*/