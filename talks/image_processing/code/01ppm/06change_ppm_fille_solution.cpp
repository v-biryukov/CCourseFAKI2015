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
    int width, height;
    std::vector<unsigned char> data;
    
    loadImagePPMP3("russian_peasants_1909_text.ppm", width, height, data);


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

    saveToFilePPMP3("result.ppm", width, height, data);
}