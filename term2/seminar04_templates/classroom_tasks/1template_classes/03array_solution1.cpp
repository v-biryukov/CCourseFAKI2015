#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
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


    T& at(size_t id) 
    {
        if (id >= Size)
        {
            throw std::out_of_range("Error. Array index is out of range!");
        }
        return data[id];
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
        a[i] = rand() % 100;
    cout << a << endl;


    
    try
    {
        cout << a[11] << endl;      // UB. Скорей всего напечатает произвольное число.
        cout << a.at(11) << endl;   // Бросит исключение.
    }
    catch (std::exception& e)
    {
        cout << e.what() << endl;
    }
}
