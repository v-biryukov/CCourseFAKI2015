#include <stdio.h>
#include <stdlib.h>

struct color
{
	unsigned char r, g, b;
};
typedef struct color Color;


int main()
{
	// Данные пикселей в картинке 3x2
	Color data[6] = {{109, 53, 35}, {116, 116, 94}, {52, 72, 49}, {40, 41, 95}, {43, 124, 53}, {58, 34, 60}};

	// Сохраняем картинку в текстовом формате
	FILE* file1 = fopen("tiny_text.ppm", "w");
	fprintf(file1, "P3\n3 2\n255\n");
	for (int i = 0; i < 6; i++) 
	{
	    fprintf(file1, "%d %d %d\n", data[i].r, data[i].g, data[i].b);
	}
	fclose(file1);


	// Сохраняем картинку в бинарном формате
	// Обратите внимание на режим открытия файла: 
	// так как файл бинарный, то нужно добавить b
	FILE* file2 = fopen("tiny_binary.ppm", "wb");
	fprintf(file2, "P6\n%d %d\n255\n", 3, 2);
	fwrite(data, sizeof(Color), 6, file2);
	fclose(file2);
}