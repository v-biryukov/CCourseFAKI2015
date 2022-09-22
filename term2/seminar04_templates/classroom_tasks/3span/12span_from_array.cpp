#include <iostream>
#include <vector>
#include <span>

void printArrayCStyle(int* array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}


void printVector(const std::vector<int>& v)
{
    for (int el : v)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}


void printSpan(std::span<int> s)
{
    for (int el : s)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}



int main()
{
    int array[6] = {4, 8, 15, 16, 23, 42};


    printArrayCStyle(array, 6);

    // Плохо так как происходит копирование всего массива в вектор
    printVector({array, array + 6});

    // Тут всё хорошо
    printSpan(array);
}