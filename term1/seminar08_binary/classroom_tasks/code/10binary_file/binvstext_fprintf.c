#include <stdio.h>


int main()
{
    FILE* f = fopen("data.txt", "w");

    fprintf(f, "Cat\nDog\nMouse\n");

    fclose(f);
}