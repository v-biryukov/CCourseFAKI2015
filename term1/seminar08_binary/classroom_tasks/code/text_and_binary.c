#include <stdio.h>


int main()
{
    int a = 0x11223344;

    // Сохраняем число a в текстовом формате:
    FILE* ft = fopen("number.txt", "w");
    fprintf(ft, "%d", a);
    fclose(ft);

    // Сохраняем число a в бинарном формате:
    FILE* fb = fopen("number.bin", "wb");
    fwrite(&a, 1, 4, fb);
    fclose(fb);
}