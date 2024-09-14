#include <typeinfo>
#include <type_traits>
#include <string>
#include <vector>
#include <iostream>
#include "type_name.hpp"
using std::cout, std::endl;


/*


*/

void bar(int& x)
{
    cout << "Lvalue" << endl;


void bar(int&& x)
{
    cout << "Rvalue" << endl;
}
template <typename T>
void foo(T&& x)
{
    bar(x);
}

int main()
{
    int a = 5;
    
    foo(5);
    foo(a);
    
    foo(5);
    foo(a);
}


/*
	Что напечатает данная программа? Объясните результат.


*/
