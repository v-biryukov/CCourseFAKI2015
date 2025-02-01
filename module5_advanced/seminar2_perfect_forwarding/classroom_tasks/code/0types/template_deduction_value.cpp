#include <typeinfo>
#include <type_traits>
#include <string>
#include <vector>
#include <iostream>
#include "type_name.hpp"
using std::cout, std::endl;

struct Book {};


template <typename T>
void func(T x)
{
    cout << typeName<decltype(x)>() << endl;
}



int main()
{
    int a = 5;
    const int b = 10;
    int& c = a;
    const int& d = a;
    int&& e = 20;

    func(a);
    func(b);
    func(c);
    func(d);
    func(e);
    func(30);
}
