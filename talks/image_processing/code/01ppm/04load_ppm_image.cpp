/*
    Считываем картинку из .ppm файла

    Так как файл текстовый, то можно просто использовать объект std::ifstream и оператор <<
    Файл .ppm не должен содержать комментарии, начинающиеся с #, иначе этот код не будет работать.
*/

#include <iostream>
#include <vector>
#include <fstream>

int main()
{
    int width;
    int height;
    int maxValue;
    std::vector<unsigned char> data;


    // Считываем файл в переменные width, height, maxValue и data:

    std::ifstream in {"tiny_text.ppm"};
    if (in.fail())
    {
        std::cout << "Error. Can't open file!" << std::endl;
        std::exit(1);
    }

    std::string type;
    in >> type;
    if (type != "P3")
    {
        std::cout << "Error. File should be type P3 .ppm file!" << std::endl;
        std::exit(1);
    }

    in >> width >> height;
    in >> maxValue;

    data.resize(3 * width * height);
    for (int j = 0; j < height; ++j)
    {
        for (int i = 0; i < width; ++i)
        {
            int r, g, b;
            in >> r >> g >> b;
            data[3 * (j * width + i) + 0] = static_cast<unsigned char>(r);
            data[3 * (j * width + i) + 1] = static_cast<unsigned char>(g);
            data[3 * (j * width + i) + 2] = static_cast<unsigned char>(b);
        }
    }


    // Печатаем считанную информацию на экран:

    std::cout << "Width = " << width << std::endl;
    std::cout << "Height = " << height << std::endl;
    std::cout << "Colors:\n";
    for (int j = 0; j < height; ++j)
    {
        for (int i = 0; i < width; ++i)
        {
            std::cout << "(" << (int)data[3 * (j * width + i) + 0] << ", " <<
                                (int)data[3 * (j * width + i) + 1] << ", " <<
                                (int)data[3 * (j * width + i) + 2] << ") ";
        }
        std::cout << "\n";
    }
}