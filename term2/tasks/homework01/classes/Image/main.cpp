#include "image.h"

int main()
{

    // Считываем картинку, изменяем и сохраняем
    Image a;
    a.read("zlatoust.ppm");
    a.reverse_colors();
    a.flip_vertically();
    a.write("a.ppm");


    // Создаём свою картинку
    int sx = 800, sy = 600, r = 150;
    Image b(sx, sy);
    for (int i = 0; i < sx; ++i)
        for (int j = 0; j < sy; ++j)
            if ((i-sx/2)*(i-sx/2) + (j-sy/2)*(j-sy/2) < r*r)
                b.set_pixel(i, j, 255, 0, 0);
            else
                b.set_pixel(i, j, 255, 255, 255);
    b.write("b.ppm");


    // Считываем картинку, и меняем её попиксельно
    // Меняем местами синий и красный цвета
    Image c("emir.ppm");
    for (int i = 0; i < c.get_size_x(); ++i)
        for (int j = 0; j < c.get_size_y(); ++j)
        {
            Pixel temp = c.get_pixel(i, j);
            unsigned char blue_color = temp.b;
            temp.b = temp.r;
            temp.r = blue_color;
            c.set_pixel(i, j, temp);
        }
    c.write("c.ppm");


    Image f("emir.ppm");
    for (int i = 0; i < f.get_size_x(); ++i)
        for (int j = 0; j < f.get_size_y(); ++j)
        {
            Pixel temp = f.get_pixel(i, j);
            double t = (temp.r + temp.g + temp.b) / 3;
            temp.r = temp.g = temp.b = t;

            f.set_pixel(i, j, temp);
        }
    f.write("f.ppm");

}