/*
    Хранение изображения в памяти

    Для того чтобы получить доступ к k-ой компоненте цвета пикселя с координатами (i, j)
    нужно взять элемент массива data с индексом  3 * (j * width + i) + k
*/

#include <iostream>

int main()
{
    const int width = 3;
    const int height = 2;

    std::vector<unsigned char> data {109, 53, 35, 116, 116, 94, 
                                     52, 72, 49, 40, 41, 95,
                                     43, 124, 53, 58, 34, 60};


    int i = 2;
    int j = 1;
    int k = 1;

    data[3 * (j * width + i) + k] = 100;
}