#include <stdio.h>
#include <stdlib.h>

// To compile:
// gcc -std=c99 -o gradient gradient.c

struct color
{
	unsigned char r, g, b;
};
typedef struct color Color;


int main()
{
	int width = 600, height = 400;
	Color* data = (Color*)malloc(sizeof(Color) * width * height);

	Color start = {50, 200, 100};
	Color finish = {50, 50, 200};

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			data[i + width * j].r = start.r + (finish.r - start.r) * 1.0 / width * i;
			data[i + width * j].g = start.g + (finish.g - start.g) * 1.0 / width * i;
			data[i + width * j].b = start.b + (finish.b - start.b) * 1.0 / width * i;
		}
	}

	FILE* file = fopen("gradient.ppm", "wb");
	fprintf(file, "P6\n%d %d\n255\n", width, height);
	fwrite(data, sizeof(Color), height * width, file);
	fclose(file);
	free(data);
}