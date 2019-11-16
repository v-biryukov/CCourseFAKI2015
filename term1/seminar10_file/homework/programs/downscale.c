#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct color
{
	unsigned char r, g, b;
};
typedef struct color Color;


struct image
{
	int width;
	int height;
	Color* data;
};
typedef struct image Image;


void init_image(Image* pimage, int width, int height)
{
	pimage->width = width;
	pimage->height = height;
	pimage->data = (Color*)malloc(sizeof(Color) * width * height);
}

void destroy_image(Image* pimage)
{
	free(pimage->data);
}

void set_pixel(Image* pimage, int x, int y, 
	unsigned char red, unsigned char green, unsigned char blue)
{
	pimage->data[x + y * pimage->width].r = red;
	pimage->data[x + y * pimage->width].g = green;
	pimage->data[x + y * pimage->width].b = blue;

}

void save_image(char filename[], const Image* pimage)
{
	FILE* file = fopen(filename, "wb");
	if (file == 0)
	{
		printf("Can't create the file: %s\n", filename);
		exit(1);
	}
	fprintf(file, "P6\n%d %d\n255\n", pimage->width, pimage->height);
	fwrite(pimage->data, sizeof(Color), pimage->width * pimage->height, file);
	fclose(file);
}

void load_image(char filename[], Image* pimage)
{
	FILE* file = fopen(filename, "rb");
	if (file == 0)
	{
		printf("Can't open the file: %s\n", filename);
		exit(1);
	}
	fscanf(file, "P6\n%d %d\n255\n", &pimage->width, &pimage->height);
	pimage->data = (Color*)malloc(sizeof(Color) * pimage->width * pimage->height);
	fread(pimage->data, sizeof(Color), pimage->width * pimage->height, file);
	fclose(file);
}


int main(int argc, char** argv)
{
	if (argc != 3)
	{
		printf("To downscale image: ./downscale <imagename> <scalefactor>");
		exit(1);
	}

	int downscale_factor;
	sscanf(argv[2], "%d", &downscale_factor);

	Image im;
	load_image(argv[1], &im);

	Image downscaled;
	init_image(&downscaled, im.width / downscale_factor, im.height / downscale_factor);

	for (int j = 0; j < downscaled.height; j++)
	{
		for (int i = 0; i < downscaled.width; i++)
		{
			Color p = im.data[(downscale_factor*i) + (downscale_factor*j) * im.width];
			set_pixel(&downscaled, i, j, p.r, p.g, p.b);
		}
	}


	char outfilename[100];
	strcpy(outfilename, argv[1]);
	outfilename[strlen(outfilename) - 4] = '\0';
	strcat(outfilename, "_downscaled.ppm");
	save_image(outfilename, &downscaled);

	destroy_image(&im);
}