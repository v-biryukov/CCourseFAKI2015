#include <iostream>
#include <string>
#include <cstdlib>

using std::cout, std::endl;


template <typename T, int size>
class Array 
{
private:
    T data[size];

public:
    T& operator[](int id) 
    {
        return data[id];
    }
     
    template <typename T2, int size2>
    friend std::ostream operator<<(std::ostream& left, const Array<T2, size2>& right);
};

template <typename T, int size>
std::ostream& operator<<(std::ostream& left, Array<T, size>& right) 
{
    cout << "[";
    for (int i = 0; i < size - 1; ++i) {
        cout << right[i] << ", ";
    }
    cout << right[size - 1] << "]"; 
    return left;
}


int main() 
{
    // Массив чисел
    Array<int, 10> numbers;
    for (int i = 0; i < 10; ++i) {
        numbers[i] = rand() % 100;
    }
    cout << numbers << endl;


    // Массив строк
    Array<std::string, 5> strings;
    strings[0] = "Cat";
    strings[1] = "Dog";
    strings[2] = "Zebra";
    strings[3] = "Elephant";
    strings[4] = "Whale";
    cout << strings << endl;


    // Массив массивов
    Array<Array<int, 5>, 5> matrix;
    for (int i = 0; i < 5; ++i) 
    {
        for (int j = 0; j < 5; ++j) 
            matrix[i][j] = rand() % 20;
    }
    cout << matrix << endl;
}