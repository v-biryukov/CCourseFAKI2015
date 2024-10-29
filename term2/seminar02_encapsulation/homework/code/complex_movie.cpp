/*
    Это программа создаёт анимацию (набор картинок) которая задаётся как меняющееся во времени
    комплексная функция (описана в функции func).
*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "complex.h"




struct Color 
{
    unsigned char r, g, b;
};

Complex func(Complex z, int time) 
{
    Complex f = 100 / (z - (0.02f * time)) * exp(z * sin(z));
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


    int maxTimeSteps = 200;
    for (int time = 0; time < maxTimeSteps; time++)
    {
        for (int j = 0; j < height; j++)
        {
            for (int i = 0; i < width; i++)
            {
                Complex z = {x0 + (x1-x0) / width * i, y0 + (y1-y0) / width * j};
                Complex f = func(z, time);
                data[i + width * j].r = 0;
                data[i + width * j].g = f.re;
                data[i + width * j].b = f.im;
            }
        }


        char filename[100];
        std::sprintf(filename, "animation/complex_%03d.ppm", time);

        FILE* file = fopen(filename, "wb");
        std::fprintf(file, "P6\n%d %d\n255\n", width, height);
        std::fwrite(data, sizeof(Color), height * width, file);
        std::fclose(file);
    }
    std::free(data);
}