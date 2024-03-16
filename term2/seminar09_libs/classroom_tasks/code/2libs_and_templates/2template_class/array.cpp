/*
    Шаблонный класс массива с фиксированным размером.

    Разделите этот файл на файлы array.cpp, array.hpp и main.cpp.
    В файла array.cpp должны производиться явное инстантацирование для типов:

        Array<int, 10>, Array<std::string, 5> и Array<Array<int, 5>, 5>
*/
#include <iostream>
#include <string>
#include <cstdlib>

template <typename T, int Size>
class Array 
{
private:
    T data[Size];

public:
    T& operator[](int id) 
    {
        return data[id];
    }
};

template <typename T, int Size>
std::ostream& operator<<(std::ostream& out, Array<T, Size> array) 
{
    out << "[";
    for (int i = 0; i < Size - 1; ++i)
        out << array[i] << ", ";
    
    if (Size != 0)
        out << array[Size - 1];

    out << "]"; 
    return out;
}

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