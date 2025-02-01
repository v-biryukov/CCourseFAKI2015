/*
    Хранение изображения в памяти

    Распечатаем всю информацию об изображении на экран
*/

#include <iostream>
#include <vector>

int main()
{
    const int width = 3;
    const int height = 2;

    std::vector<unsigned char> data {109, 53, 35, 116, 116, 94, 
                                     52, 72, 49, 40, 41, 95,
                                     43, 124, 53, 58, 34, 60};


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