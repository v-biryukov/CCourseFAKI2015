/*
    Записываем картинку .ppm в файл, вариант формата P6

    Вариант формата ppm P6 - это бинарный формат файла.
    Но при этом, заголовок файла (первые 3 строки) всё-равно хранится в текстовом формате.
    Поэтому сначала нам нужно записать в файл следующее:

        P6
        200 100
        255

    А потом нужно записать компоненты цветов пикселей, по 3 байта на цвет.
    Это делается с помощью метода write класса std::ofstream. 
    Этот метод принимает указатель на данные типа const char* и количество байт для записи.
    Все данные хранятся внутри объекта data типа std::vector, по адресу &data[0].
    Правда нужно будет конвертировать указатель из типа unsigned char* в const char*
*/

#include <iostream>
#include <vector>
#include <fstream>

int main()
{
    const int width = 200;
    const int height = 100;
    std::vector<unsigned char> data(3 * width * height);
    for (int j = 0; j < height; ++j)
    {
        for (int i = 0; i < width; ++i)
        {
            data[3 * (j * width + i) + 0] = 40;
            data[3 * (j * width + i) + 1] = 80;
            data[3 * (j * width + i) + 2] = 120;
        }
    }

    std::ofstream out {"result.ppm", std::ios::binary};

    out << "P6\n" << width << " " << height << "\n255\n";
    out.write(reinterpret_cast<const char*>(&data[0]), data.size());
}