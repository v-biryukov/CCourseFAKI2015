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

    char str[100];
    fread(str, 1, 100, f);

    int i = 0;
    while (str[i])
    {
        print_char(str[i]);
        printf(": %i\n", str[i]);
        ++i;
    }

}