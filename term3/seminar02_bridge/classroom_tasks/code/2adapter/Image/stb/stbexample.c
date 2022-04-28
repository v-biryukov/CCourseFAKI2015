#include <stdio.h>

#include "stb_image.h"
#include "stb_image_write.h"


int main()
{
	int width;
	int height;
	int ncomponents;

	// Загружаем файл, используя библиотеку stb
	unsigned char* image = stbi_load("sky.jpg", &width, &height, &ncomponents, STBI_rgb);

	// Рисуем шахматную сетку на картинке
	for (int j = 0; j < width; ++j)
		for (int i = 0; i < height; ++i)
		{
			if ((i + j) % 2 == 0)
			{
				image[ncomponents * (i * width + j) + 0] = 0;
				image[ncomponents * (i * width + j) + 1] = 0;
				image[ncomponents * (i * width + j) + 2] = 0;
			}
		}
	
	// Сохраняем изображение в форматах .jpg с качеством 90
	stbi_write_jpg("res.jpg", width, height, ncomponents, image, 90);

	// Сохраняем изображение в форматах .png
	stbi_write_png("res.png", width, height, ncomponents, image, 0);

}