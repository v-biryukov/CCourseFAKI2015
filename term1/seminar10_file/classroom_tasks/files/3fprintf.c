#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE* fp = fopen("myfile.txt", "w");
    if (fp == NULL)
    {
        printf("Error!\n");
        exit(1);
    }
    fprintf(fp, "Hello world!\n");
    fclose(fp);
}