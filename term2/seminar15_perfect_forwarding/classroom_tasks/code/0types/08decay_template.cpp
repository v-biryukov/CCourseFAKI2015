#include <iostream>
#include "type_name.hpp"

using std::cout, std::endl;

/*
	Такой же decay происходит при выводе типа в шаблонах
*/

template <typename T>
void func(T x)
{
    cout << "func: T =      \t" <<  typeName<T>() << endl;
    cout << "func: x type = \t" <<  typeName<decltype(x)>() << endl;
}



int main()
{
    int a[10] = {};
    cout << "main: a type = \t" <<  typeName<decltype(a)>() << endl;

    func<decltype(a)>(a);
    func(a);
}



/*
	Задачи:
	
	1)	Что напечатает данная программа?

*/

