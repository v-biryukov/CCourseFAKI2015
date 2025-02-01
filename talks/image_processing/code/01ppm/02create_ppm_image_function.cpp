/*
    Записываем картинку .ppm в файл

    Если данные о цветах пикселей хранятся в контейнере std::vector, то их тоже легко записать в файл.

    Напишем функцию, которая будет записывать данные из вектора в файл формата .ppm (P3)
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>


void saveToFilePPMP3(const std::string& filename, int width, int height, const std::vector<unsigned char>& data)
{
    std::ofstream out {filename};
    out << "P3\n" << width << " " << height << "\n255\n";
    for (int j = 0; j < height; ++j)
    {
        for (int i = 0; i < width; ++i)
        {
            out << (int)data[3 * (j * width + i) + 0] << " " 
                << (int)data[3 * (j * width + i) + 1] << " " 
                << (int)data[3 * (j * width + i) + 2] << "\n";
        }
    }
}

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

    saveToFilePPMP3("my_image.ppm", width, height, data);
}