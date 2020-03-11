#include <iostream>
#include <cstdlib>
#include "stb_image.h"
#include "stb_image_write.h"
#include "stb_perlin.h"

using namespace std;

int main(void) 
{
	int width = 500, height = 500;
	unsigned char* data = new unsigned char[width * height];

	float scale = 0.05;

	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			{
				unsigned char t = 100* (1 + stb_perlin_noise3(scale*i, scale*j, 4.51, 0, 0, 0));
				//cout << (int)t << endl;
				data[i + width * j] = t;
			}


	stbi_write_jpg("perlin.jpg", width, height, 1, data, 10);
	delete[] data;
}