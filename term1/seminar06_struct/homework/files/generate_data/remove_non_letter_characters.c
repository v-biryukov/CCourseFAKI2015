#include <stdio.h>



int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("Usage:\n");
        printf("./remove_non_letter_characters <file to read from> <new save file>\n");
    }

    FILE* fin = fopen(argv[1], "r");
    FILE* fout = fopen(argv[2], "w");
    int c = 1;
    while ((c = fgetc(fin)) != EOF) 
    {
        //printf("%d ", c);
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '\n')
            fputc(c, fout);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}