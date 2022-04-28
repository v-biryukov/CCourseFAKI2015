#include <string>
#include <vector>
#include <iostream>
#include "type_name.hpp"

using std::cout, std::endl;



template <typename T>
void func(T x)
{
    x++;
}



int main()
{
    int a = 123;
    cout << a << endl;

    func(a);
    cout << a << endl;

    func<int&>(a);
    cout << a << endl;


    func<int&&>(std::move(a));
    cout << a << endl;
}