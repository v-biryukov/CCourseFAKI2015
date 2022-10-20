#include <stdio.h>
#include <stdlib.h>

void print_char(unsigned char c)
{
    if (c < 32 || c > 127)
        printf(".");
    else
        printf("%c", c);
}

int main(int argc, char** argv)
{
    if (argc != 2) {printf("Error, argc should be equal to 2\n"); exit(1);}

    FILE* f = fopen(argv[1], "r");
    // FILE* f = fopen(argv[1], "rb");

    while (1)
    {
        int c = fgetc(f);

        if (c == EOF)
            break;

        print_char(c);
        printf(": %i\n", c);
    }
}