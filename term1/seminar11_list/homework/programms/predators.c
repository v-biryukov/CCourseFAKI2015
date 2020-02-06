#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>


struct color
{
	unsigned char r, b, g;
};
typedef struct color Color;

const int animal_radius = 7;
const Color prey_color = {100, 200, 100};
const Color predator_color = {220, 80, 80};

struct animal
{
	float x, y;
	float vx, vy;
	int type;
};
typedef struct animal Animal;

struct image
{
	Color* data;
	int width;
	int height;
};
typedef struct image Image;


int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a < b ? a : b;
}
int sqr(int a)
{
	return a*a;
}

Image create_image(int width, int height)
{
	Image new_image;
	new_image.width = width;
	new_image.height = height;
	new_image.data = (Color*)malloc(width * height * sizeof(Color));
	return new_image;
}

void destroy_image(Image* image)
{
	if (image->data)
		free(image->data);
	image->width = 0;
	image->height = 0;
}

void save_image(char* filename, const Image* image)
{
	FILE* file = fopen(filename, "wb");
	fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
	fwrite(image->data, sizeof(Color), image->height * image->width, file);
	fclose(file);
}

void clear_image(Image* image)
{
	memset(image->data, 0, image->width * image->height * sizeof(Color));
}



void draw_animal(Image* image, Animal animal)
{
	Color c;
	if (animal.type == 0)
		c = prey_color;
	else
		c = predator_color;
	int imin = max(animal.x - animal_radius, 0);
	int imax = min(animal.x + animal_radius, image->width);
	int jmin = max(animal.y - animal_radius, 0);
	int jmax = min(animal.y + animal_radius, image->height);
	for (int i = imin; i < imax; i++)
		for (int j = jmin; j < jmax; j++)
		{
			if (sqr(i-animal.x) + sqr(j-animal.y) < sqr(animal_radius))
				image->data[i + image->width * j] = c;
		}
}

void draw_animals(Image* image, Animal* animal_array, int animal_count)
{
	for (int i = 0; i < animal_count; i++)
		draw_animal(image, animal_array[i]);
}

void step(const Image* image, Animal* animals, int animal_count)
{
	float coef = 3;
	for (int i = 0; i < animal_count; i++)
		for (int j = 0; j < animal_count; j++)
		{
			float dist = sqrt(sqr(animals[j].x - animals[i].x) + sqr(animals[j].y - animals[i].y));
			if (dist < 3)
				dist = 3;
			if (animals[i].type == 1 && animals[j].type == 0)
			{
				animals[i].vx += coef*(animals[j].x - animals[i].x)/(dist*dist);
				animals[i].vy += coef*(animals[j].y - animals[i].y)/(dist*dist);
			}
			if (animals[i].type == 0 && animals[j].type == 1)
			{
				animals[i].vx -= coef*(animals[j].x - animals[i].x)/(dist*dist);
				animals[i].vy -= coef*(animals[j].y - animals[i].y)/(dist*dist);
			}
		}

	for (int i = 0; i < animal_count; i++)
	{
		animals[i].x += animals[i].vx;
		animals[i].y += animals[i].vy;
		if (animals[i].x > image->width)
			animals[i].x -= image->width;
		if (animals[i].x < 0)
			animals[i].x += image->width;
		if (animals[i].y > image->height)
			animals[i].y -= image->height;
		if (animals[i].y < 0)
			animals[i].y += image->height;
	}
}

int main()
{
	srand(time(0));
	Image world = create_image(500, 500);
	Animal a = {200, 200, 0, 0, 1};
	Animal arr[100];
	for (int i = 0; i < 100; i++)
	{
		arr[i].x = rand() % 500;
		arr[i].y = rand() % 500;
		arr[i].vx = 0;
		arr[i].vy = 0;
		arr[i].type = rand() % 2;
	}
	//draw_animals(&world, arr, 100);
	//save_image("world1.ppm", &world);
	//clear_image(&world);
	//step(arr, 100);


	for (int i = 0; i < 500; i++)
	{
		char filename[50];
		sprintf(filename, "world_%03d.ppm", i);
		draw_animals(&world, arr, 100);
		save_image(filename, &world);
		step(&world, arr, 100);
		clear_image(&world);
	}


}