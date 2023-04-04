#include "image.h"
#include "drawer.h"


int main()
{
    // Создаём свою картинку размера 1000 на 800 пикселей
    Image b(1000, 800);
    // Задаём её случайными цветами
    draw_random(b);

    // Сохраняем картинку в файл
    b.write("b.ppm");
}