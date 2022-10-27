#include <iostream>
#include <string>
#include <cstdlib>

#include "array.hpp"

int main() 
{
    // Массив чисел
    Array<int, 10> numbers;
    for (int i = 0; i < 10; ++i)
        numbers[i] = rand() % 100;
    std::cout << numbers << std::endl;


    // Массив строк
    Array<std::string, 5> strings;
    strings[0] = "Cat";
    strings[1] = "Dog";
    strings[2] = "Zebra";
    strings[3] = "Elephant";
    strings[4] = "Whale";
    std::cout << strings << std::endl;


    // Массив массивов
    Array<Array<int, 5>, 5> matrix;
    for (int i = 0; i < 5; ++i) 
    {
        for (int j = 0; j < 5; ++j) 
            matrix[i][j] = rand() % 4;
    }
    std::cout << matrix << std::endl;
}