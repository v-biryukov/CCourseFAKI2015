/*
    Работа с изображениями формата .ppm, вариант формата P6

    Теперь мы можем считывать и записывать файлы формата .ppm P6.
    Создадим программу, которая будет считывать картинку, делать её чёрно-белой и записывать в файл.
*/

#include <iostream>
#include <vector>
#include <fstream>



void loadImagePPMP6(const std::string& filename, int& rWidth, int& rHeight, std::vector<unsigned char>& rData)
{
    std::ifstream in {filename, std::ios::binary};
    if (in.fail())
    {
        std::cout << "Error. Can't open file!" << std::endl;
        std::exit(1);
    }

    std::string type;
    in >> type;
    if (type != "P6")
    {
        std::cout << "Error. File should be type P6 .ppm file!" << std::endl;
        std::exit(1);
    }

    in >> rWidth >> rHeight;

    int maxValue;
    in >> maxValue;

    char temp;
    in >> std::noskipws >> temp;

    rData.resize(3 * rWidth * rHeight);
    in.read(reinterpret_cast<char*>(&rData[0]), rData.size());
}


void saveImagePPMP6(const std::string& filename, int width, int height, const std::vector<unsigned char>& data)
{
    std::ofstream out {filename, std::ios::binary};
    out << "P6\n" << width << " " << height << "\n255\n";
    out.write(reinterpret_cast<const char*>(&data[0]), data.size());
}



int main()
{
    int width, height;
    std::vector<unsigned char> data;
    loadImagePPMP6("house_binary.ppm", width, height, data);

    // Делаем изображение черно-белым
    for (int j = 0; j < height; ++j)
    {
        for (int i = 0; i < width; ++i)
        {
            int average = (data[3 * (j * width + i) + 0] + 
                           data[3 * (j * width + i) + 1] + 
                           data[3 * (j * width + i) + 2]) / 3;


            if (average > 255)
                average = 255;

            data[3 * (j * width + i) + 0] = average;
            data[3 * (j * width + i) + 1] = average;
            data[3 * (j * width + i) + 2] = average;
        }
    }

    saveImagePPMP6("result.ppm", width, height, data);
}