
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using std::cout, std::endl, std::size_t;


template <typename T, size_t Size>
class Array 
{
private:
    T data[Size];

public:
    T& operator[](size_t id) 
    {
        return data[id];
    }


    void sort()
    {
        for (size_t j = 0; j < Size; ++j)
        {
            size_t min_index = j;
            for (size_t i = j + 1; i < Size; ++i)
            {
                if (data[i] < data[min_index])
                    min_index = i;
            }

            T temp = data[j];
            data[j] = data[min_index];
            data[min_index] = temp;
        }
    }


    bool operator<(const Array& right) const
    {
        size_t i = 0;
        while (i < Size && data[i] == right.data[i])
        {
            i += 1;
        }

        if (i == Size)
        {
            return false;
        }

        return data[i] < right.data[i];
    }

};

template <typename T, size_t Size>
std::ostream& operator<<(std::ostream& out, Array<T, Size> array) 
{
    out << "[";
    for (size_t i = 0; i < Size - 1; ++i)
        out << array[i] << ", ";
    
    if (Size != 0)
        out << array[Size - 1];

    out << "]"; 
    return out;
}


int main() 
{
    std::srand(std::time(nullptr));

    Array<int, 10> a;
    for (int i = 0; i < 10; ++i)
    {
        a[i] = rand() % 100;
    }

    cout << a << endl;
    a.sort();
    cout << a << endl;


    Array<std::string, 5> b;
    b[0] = "Cat";
    b[1] = "Dog";
    b[2] = "Zebra";
    b[3] = "Elephant";
    b[4] = "Whale";

    cout << b << endl;
    b.sort();
    cout << b << endl;



    Array<Array<int, 5>, 5> matrix;
    for (int i = 0; i < 5; ++i) 
    {
        for (int j = 0; j < 5; ++j) 
            matrix[i][j] = rand() % 4;
    }

    cout << matrix << endl;
    matrix.sort();
    cout << matrix << endl;
}