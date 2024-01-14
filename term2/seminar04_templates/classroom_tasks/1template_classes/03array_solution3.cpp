
#include <iostream>
#include <string>
#include <cstdlib>
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
    Array<int, 10> a;
    for (int i = 0; i < 10; ++i)
    {
        a[i] = rand() % 100;
    }

    cout << a << endl;
    a.sort();
    cout << a << endl;
}