#include <iostream>
#include "type_name.hpp"

using std::cout, std::endl;
/*

*/

void func(int x[])
{
    cout << "func: x size:\t" <<  sizeof(x) << endl;
    cout << "func: x type:\t" <<  typeName<decltype(x)>() << endl;
}


void func2(int x)
{
    cout << "func2: x type:\t" <<  typeName<decltype(x)>() << endl;
}



int main()
{
    cout << "Array decay:" << endl;
    int a[10] = {};

    cout << "main: a size:\t" <<  sizeof(a) << endl;
    cout << "main: a type:\t" <<  typeName<decltype(a)>() << endl;
    func(a);



    cout << endl << "Const ref decay:" << endl;

    const int&& b = 123;
    cout << "main : b type:\t" <<  typeName<decltype(b)>() << endl;
    
    func2(b);
}