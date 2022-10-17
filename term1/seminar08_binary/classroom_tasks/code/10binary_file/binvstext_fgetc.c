#include <stdio.h>


void print_char(unsigned char c)
{
    if (c < 32 || c > 127)
        printf(".");
    else
        printf("%c", c);
}

int main()
{
    FILE* f = fopen("test.txt", "r");
    // FILE* f = fopen("test.txt", "rb");

    while (1)
    {
        int c = fgetc(f);

        if (c == EOF)
            break;

        print_char(c);
        printf(": %i\n", c);
    }
}