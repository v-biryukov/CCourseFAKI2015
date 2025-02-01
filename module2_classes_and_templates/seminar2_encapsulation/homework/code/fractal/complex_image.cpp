/*
    В этой программе мы рисуем в картинку комплексную функцию, которая задаётся в функции func.

    В функции main используем объект класса Image из image.hpp, чтобы создать изображение размером 800 на 800 пикселей.
    Задаём значения этого массива так, чтобы реальная часть функции func соответствовала зелёному цвету,
    а мнимая часть -- синей компоненте цвета.

    Сохраняем изображение, заданное массивом data в изображение complex_image.ppm.
    Для сохранения используем метод класса Image.
*/

#include <vector>
#include <cmath>
#include "complex.hpp"
#include "image.hpp"

Complex func(Complex z) 
{
    Complex f = 100 / z;
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

    for (int j = 0; j < image.getHeight(); j++) 
    {
        for (int i = 0; i < image.getWidth(); i++) 
        {
            Complex z = {x0 + (x1-x0) / image.getWidth() * i, y0 + (y1-y0) / image.getWidth() * j};
            Complex f = func(z);

            Image::Color c = {0, static_cast<unsigned char>(f.re), static_cast<unsigned char>(f.im)};
            image.setPixel(i, j, c);
        }
    }

    image.savePPMBinary("complex_image.ppm");
}