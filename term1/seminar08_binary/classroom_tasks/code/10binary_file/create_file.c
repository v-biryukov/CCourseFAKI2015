#include <stdio.h>


int main()
{
    FILE* f = fopen("test.txt", "wb");

    for (int i = 0; i < 256; ++i)
    {
        fputc((char)i, f);
    }

    fclose(f);
}