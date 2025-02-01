/*
    Это программа создаёт анимацию (набор картинок) которая задаётся как меняющееся во времени
    комплексная функция (описана в функции func).
*/

#include <vector>
#include <cmath>
#include "complex.hpp"
#include "image.hpp"

Complex func(Complex z, int time) 
{
    Complex f = 100 * sin(1 / z + 0.1 * time);
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
    Image image(800, 800);
    float x0 = -2, x1 = 2;
    float y0 = -2, y1 = 2;


    int maxTimeSteps = 100;
    for (int time = 0; time < maxTimeSteps; time++)
    {
        for (int j = 0; j < image.getHeight(); j++)
        {
            for (int i = 0; i < image.getWidth(); i++)
            {
                Complex z = {x0 + (x1-x0) / image.getWidth() * i, y0 + (y1-y0) / image.getWidth() * j};
                Complex f = func(z, time);

                Image::Color c = {0, static_cast<unsigned char>(f.re), static_cast<unsigned char>(f.im)};
                image.setPixel(i, j, c);
            }
        }

        char filename[100];
        std::sprintf(filename, "animation/complex_%03i.ppm", time);

        image.savePPMBinary(filename);
    }
}