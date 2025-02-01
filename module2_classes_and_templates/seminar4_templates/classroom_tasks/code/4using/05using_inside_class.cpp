/*
    using алиасы

    В языке C, чтобы дать новое имя для типа нужно было использовать typedef.
    В C++ появился новый, более удобный способ дать типы новое имя, с помощью ключевого слова using.


    Да слово using используется не только для добавления имён из пространств имён, но ещё и для того, чтобы
    давать новые имена типам.

    В данной программе имена cat и dog это новые имена для типа unsigned long long.
*/


#include <iostream>
using std::cout, std::endl;

template <typename T, size_t Size>
class Array 
{


public:
    T& operator[](size_t id) 
    {
        return data[id];
    }

private:
    T data[Size];
};



int main()
{
    Complex<float> c {1, 2};

    Complex<float>::ValueType x = c.re();
}

