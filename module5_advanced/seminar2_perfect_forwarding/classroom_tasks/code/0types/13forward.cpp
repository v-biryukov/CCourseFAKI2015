#include <typeinfo>
#include <type_traits>
#include <string>
#include <vector>
#include <iostream>
#include "type_name.hpp"
using std::cout, std::endl;


/*
	Специальная функция std::forward<T>(x) делает следующее:
	
		- Если T - это не ссылочный тип, то конвертирует x в rvalue
		- Если T - это ссылка, то ничего не делает

*/

void bar(int& x)
{
    cout << "Lvalue" << endl;
}

void bar(int&& x)
{
    cout << "Rvalue" << endl;
}


template <typename T>
void foo(T&& x)
{
    bar(std::forward<T>(x));
}


int main()
{
    int a = 5;
    
    bar(5);
    bar(a);
    
    foo(5);
    foo(a);
}


/*
	Что напечатает данная программа? Объясните результат.


*/
