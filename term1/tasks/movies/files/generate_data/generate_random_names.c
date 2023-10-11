#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "generate_random_names.h"

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        printf("Usage:\n");
        printf("generate_random_names <number of names> <file to save the names>\n");
        return 1;
    }

    int number_of_names_to_generate;
    sscanf(argv[1], "%d", &number_of_names_to_generate);

    FILE* fout = fopen(argv[2], "w");

    generate_random_names(fout, number_of_names_to_generate, "female_names.txt", "male_names.txt", "surnames.txt");

    fclose(fout);
}

