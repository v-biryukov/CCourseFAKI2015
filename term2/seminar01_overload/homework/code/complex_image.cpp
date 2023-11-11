/*
    В этой программе мы рисуем в картинку комплексную функцию, которая задаётся в функции func.

    В функции main выделенный на куче массив data - это массив цветов размером width * height.
    Задаём значения этого массива так, чтобы реальная часть функции func соответствовала зелёному цвету,
    а мнимая часть -- синей компоненте цвета.

    Сохраняем изображение, заданное массивом data в изображение complex_image.ppm.
    Для сохранения используем функции стандартной библиотеки языка C: fopen, fprintf, fwrite, fclose.
    Так как мы прошли эти функции в предыдущем семестре.
    Но то же самое можно было сделать и с помощью средств стандартной библиотеки языка C++: класса std::ofstream.
*/


#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "complex.h"


struct Color 
{
    unsigned char r, g, b;
};

Complex func(Complex z) 
{
    Complex f = 100 / (z - 1) * exp(z);
    f.re = std::abs(f.re);
    f.im = std::abs(f.im);
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

    Color* data = (Color*)std::malloc(sizeof(Color) * width * height);

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

    FILE* file = std::fopen("complex_image.ppm", "wb");
    std::fprintf(file, "P6\n%d %d\n255\n", width, height);
    std::fwrite(data, sizeof(Color), height * width, file);
    std::fclose(file);

    std::free(data);
}