#include <iostream>
#include <functional>
#include "type_name.hpp"

using std::cout, std::endl;
/*
    В языке C++ есть множество функциональных объектов, но
    все они имеют разный тип
*/

void func(int x)
{
    cout << x << endl;
}



int main()
{
    cout << "func type: " <<  typeName<decltype(func)>() << endl;

    auto* p = func;
    cout << "p type:    " <<  typeName<decltype(p)>() << endl;

    auto& r = func;
    cout << "r type:    " <<  typeName<decltype(r)>() << endl;

    std::function<void(int)> f = func;
    cout << "f type:    " <<  typeName<decltype(f)>() << endl;

    auto l = [](int x) {cout << x << endl;};
    cout << "l type:    " <<  typeName<decltype(l)>() << endl;

}