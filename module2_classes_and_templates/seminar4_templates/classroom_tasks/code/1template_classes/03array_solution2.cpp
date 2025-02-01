
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

    void reverse()
    {
        for (size_t i = 0; i < Size / 2; ++i)
        {
            T temp(data[Size - 1 - i]);
            data[Size - 1 - i] = data[i];
            data[i] = temp;
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
    Array<std::string, 5> b;
    b[0] = "Cat";
    b[1] = "Dog";
    b[2] = "Zebra";
    b[3] = "Elephant";
    b[4] = "Whale";


    cout << b << endl;
    b.reverse();
    cout << b << endl;
}