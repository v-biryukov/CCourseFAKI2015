
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


template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, std::pair<T, U> p) 
{
    out << "(";
    out << p.first;
    out << ", ";
    out << p.second;
    out << ")"; 
    return out;
}


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
    Array<std::pair<std::string, int>, 5> a;
    a[0] = std::pair("Cat", 7);
    a[1] = std::pair("Cat", 5);
    a[2] = std::pair("Dog", 2);
    a[3] = std::pair("Ant", 1);
    a[4] = std::pair("Cat", 4);

    cout << a << endl;
    a.sort();
    cout << a << endl;
}