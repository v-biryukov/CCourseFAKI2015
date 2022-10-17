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
    FILE* f = fopen("test.txt", "rb");
    // FILE* f = fopen("test.txt", "rb");

    char str[100];
    fscanf(f, "%[^\n]", str);


    int i = 0;
    while (str[i])
    {
        print_char(str[i]);
        printf(": %i\n", str[i]);
        ++i;
    }

}