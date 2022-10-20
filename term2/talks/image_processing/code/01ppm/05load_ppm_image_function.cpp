/*
    Считываем картинку из .ppm файла

    Так как файл текстовый, то можно просто использовать объект std::ifstream и оператор <<
    Файл .ppm не должен содержать комментарии, начинающиеся с #, иначе этот код не будет работать.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>


void loadImagePPMP3(const std::string& filename, int& rWidth, int& rHeight, std::vector<unsigned char>& rData)
{
    std::ifstream in {filename};
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

    in >> rWidth >> rHeight;

    int maxValue;
    in >> maxValue;

    rData.resize(3 * rWidth * rHeight);
    for (int j = 0; j < rHeight; ++j)
    {
        for (int i = 0; i < rWidth; ++i)
        {

            int r, g, b;
            in >> r >> g >> b;
            rData[3 * (j * rWidth + i) + 0] = static_cast<unsigned char>(r);
            rData[3 * (j * rWidth + i) + 1] = static_cast<unsigned char>(g);
            rData[3 * (j * rWidth + i) + 2] = static_cast<unsigned char>(b);
        }
    }
}

int main()
{
    int width, height;
    std::vector<unsigned char> data;
    loadImagePPMP3("tiny_text.ppm", width, height, data);

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