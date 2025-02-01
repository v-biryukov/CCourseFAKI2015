#include <typeinfo>
#include <type_traits>
#include <string>
#include <vector>
#include <iostream>
using std::cout, std::endl;

#include "type_name.hpp"

struct Book {};


template <typename T>
void func(T& x)
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

	int* p = &a;
    func(p);
    func(b);
    func(c);
    func(d);
    func(e);
    // func(30);
}
