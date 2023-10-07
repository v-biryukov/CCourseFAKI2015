#include <stdio.h>

int main()
{
    FILE* file = fopen("hello.txt", "w");

    fprintf(file, "Hello file!\n");

    int a = 123;
    fprintf(file, "%i\n", a);

    float numbers[] = {5.2, 1.5, 2.1, 0.4, 7.2};
    for (int i = 0; i < 5; ++i)
        fprintf(file, "%f ", numbers[i]);

    fclose(file);
}