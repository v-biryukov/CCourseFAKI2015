#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "complex.h"
using namespace std;

struct Color
{
	unsigned char r, g, b;
};

Complex func(Complex z)
{
	Complex f = 100/(z - 1)*exp(z);
	//Complex f = 50*sin(z/(z + 1));
	f.re = fabs(f.re);
	f.im = fabs(f.im);
	if (f.re > 255)
		f.re = 255;
	if (f.im > 255)
		f.im = 255;
	return f;
}


int main()
{
	int width = 800, height = 800;
	float x0 = -2.0f, x1 = 2.0f;
	float y0 = -2.0f, y1 = 2.0f;
	Color* data = (Color*)malloc(sizeof(Color) * width * height);

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			Complex z = {x0 + (x1-x0) / width * i, y0 + (y1-y0) / width * j};
			Complex f = func(z);
			data[i + width * j].r = 0;
			data[i + width * j].g = f.re;
			data[i + width * j].b = f.im;
		}
	}

	FILE* file = fopen("complex_image.ppm", "wb");
	fprintf(file, "P6\n%d %d\n255\n", width, height);
	fwrite(data, sizeof(Color), height * width, file);
	fclose(file);
	free(data);
}