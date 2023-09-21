#include <stdio.h>
#include <stdlib.h>

/*
    Данная программа подсчитывает количество символов в файле

*/

int main() {
    FILE* f = fopen("books/war_and_peace.txt", "r");
    if (f == NULL) 
    {
        printf("Can't open file!\n");
        exit(1);
    }
    int c; 
    int num_of_digits = 0;

    while ((c = fgetc(f)) != EOF) {
        if (c >= '0' && c <= '9')
            num_of_digits += 1;
    }
    printf("Number of digits = %d\n", num_of_digits);
    fclose(f);
}