/*
    Псевдонимы типов, определённые внутри контейнеров можно использоваться и в качестве
    типа возвращаемого значения.
*/


#include <iostream>
#include <vector>
#include <string>
#include <array>
using std::cout, std::endl, std::string;

template <typename T>
typename T::value_type func(T c)
{
    typename T::value_type x = c[0] + c[1];
    return x;
}


int main()
{
    std::array  a {10, 20, 30, 40, 50};
    std::vector v {string("Cat"), string("Dog")};


    cout << func(a) << endl;
    cout << func(v) << endl;
}

