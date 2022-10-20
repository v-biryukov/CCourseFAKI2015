/*
    Считываем картинку .ppm из файла, вариант формата P6

    Вариант формата ppm P6 - это бинарный формат файла.
    Но при этом, заголовок файла (первые 3 строки) всё-равно хранится в текстовом формате.

    Поэтому сначала нам нужно считать из файла следующее:

        P6
        200 100
        255

    Это можно сделать обычным способом, с помощью оператора >>  

    Перед тем, как считывать цвета пикселей нужно считать символ переноса строки.
    Дело в том, что после считывания числа 255 в буфере остался символ переноса строки \n.
    Его нужно считать вот так:

        char temp;
        in >> std::noskipws >> temp;

    Флаг std::noskipws нужен чтобы не пропусвать пробельные символы. 
    Так как при считывании с помощью << пробельные символы пропускаются.
    Если бы этого флага не было бы, то \n при считывании пропустился бы и в переменную temp считался бы первый байт первого пикселя.


    Потом нужно записать компоненты цветов пикселей, по 3 байта на цвет.
    Это делается с помощью метода write класса std::ifstream. 
    Этот метод принимает указатель на данные типа const char* и количество байт для записи.
    Все данные хранятся внутри объекта data типа std::vector, по адресу &data[0].
    Правда нужно будет конвертировать указатель из типа unsigned char* в const char*
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

    std::ifstream in {"tiny_binary.ppm", std::ios::binary};
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

    in >> width >> height;
    in >> maxValue;

    // После того как считали число 255 нужно считать ещё 1 символ переноса строки \n.
    // Флаг std::noskipws нужен чтобы не пропусвать пробельные символы.
    // Если бы этого флага не было бы, то \n при считывании пропустился бы и в переменную temp считался бы первый байт первого пикселя.
    char temp;
    in >> std::noskipws >> temp;

    data.resize(3 * width * height);
    in.read(reinterpret_cast<char*>(&data[0]), data.size());



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