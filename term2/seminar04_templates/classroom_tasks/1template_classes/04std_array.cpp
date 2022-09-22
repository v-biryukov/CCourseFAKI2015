/*
    В стандартной библиотеки C++ уже есть класс массив с фиксированным размером.
    Это std::arraу из библиотеки array.

    Правда у него не определён перегруженный оператор << с объектом std::ostream.
    Поэтому его обычно печатают поэлементно. Но можно самим написать этот перегруженный оператор.

    std::array<T, N> является аналогом обычного массива T[N], пришедшего из C, но гораздо удобней, 
    поэтому по возможности следует использовать std::array вместо обычных массивов.
    std::array такой же быстрый как и обычный массив и у него нет никаких других недостатков.
*/



#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
using std::cout, std::endl;

template <class T, std::size_t Size>
std::ostream& operator<<(std::ostream& out, const std::array<T, Size>& arr)
{
    out << "[";
    for (std::size_t i = 0; i < Size - 1; ++i)
        out << arr[i] << ", ";

    if (Size != 0)
        out << arr[Size - 1];
    out << "]";

    return out;
}

int main() 
{
    // Массив чисел
    std::array<int, 10> numbers;
    for (int i = 0; i < 10; ++i)
        numbers[i] = rand() % 100;
    cout << numbers << endl;


    // Массив строк
    std::array<std::string, 5> strings;
    strings[0] = "Cat";
    strings[1] = "Dog";
    strings[2] = "Zebra";
    strings[3] = "Elephant";
    strings[4] = "Whale";
    cout << strings << endl;
    

    // Массив массивов
    std::array<std::array<int, 5>, 5> matrix;
    for (int i = 0; i < 5; ++i) 
    {
        for (int j = 0; j < 5; ++j) 
            matrix[i][j] = rand() % 4;
    }
    cout << matrix << endl;
}

