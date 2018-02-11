#include <stdio.h>
#include <stdlib.h>

struct color
{
    unsigned char r, g, b;
};
typedef struct color Color;

void write_ppm(const char* filename, int n, int m, int** arr)
{
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "P6\n#\n%d %d\n255\n", n, m);
    // Используйте функцию fwrite, чтобы записать 
    // Пример записи 1 пикселя в файл:
    // Color c = {128, 64, 128};
    // fwrite(&с, 1, 3, fp);
    // Нужно записать n x m пикселей
    fclose(fp);
}

void read_ppm(const char* filename, int* pn, int* pm, int*** parr)
{
    FILE* fp = fopen(filename, "r");
    char temp_str[200];
    fscanf(fp, "%[^\n]\n", temp_str);
    fscanf(fp, "%[^\n]\n", temp_str);
    fscanf(fp, "%d %d", pn, pm);
    fscanf(fp, "%[^\n]\n", temp_str);
    int n = *pn;
    int m = *pm;

    *parr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i)
        (*parr)[i] = (int*)malloc(m * sizeof(int));

    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            Color black = {0, 0, 0};
            Color white = {255, 255, 255};
            Color temp;
            fread(&temp, 1, 3, fp);
            if (temp.r == black.r)
                (*parr)[i][j] = -2;
            else
                (*parr)[i][j] = -1;
        }
    }
    fclose(fp);
}