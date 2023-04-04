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