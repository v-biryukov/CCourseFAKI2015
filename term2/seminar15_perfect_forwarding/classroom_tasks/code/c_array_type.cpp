#include <iostream>
#include "type_name.hpp"

using std::cout, std::endl;
/*

*/

void func(int (&x)[10])
{
    x[0] = 777;
    cout << "func: x size: " <<  sizeof(x) << endl;
    cout << "func: x type: " <<  typeName<decltype(x)>() << endl;
}




int main()
{

    cout << "Array decay:" << endl;
    int a[10] = {};

    cout << "main: a type: " <<  typeName<decltype(a)>() << endl;
    func(a);

    cout << a[0] << endl;
}