#include <stdio.h>
#include <stdlib.h>


/*
    Данная программа создаёт файл и записывает в него
    строку Hello world!

*/



int main() {

    FILE* fp = fopen("myfile.txt", "w");
    if (fp == NULL) {
        printf("Error!\n");
        exit(1);
    }
    fprintf(fp, "Hello world!\n");
    fclose(fp);
}