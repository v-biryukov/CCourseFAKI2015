#include <typeinfo>
#include <type_traits>
#include <string>
#include <vector>
#include <iostream>
#include "type_name.hpp"
using std::cout, std::endl;


/*
	Правила свёртки ссылок:
	Если в процессе подстановки типа получаются выражения вида ссылка на ссылку,
	то они преобразуются по следующим правилам:
	
		Т& &      -->      T&
		Т& &&     -->      T&
		Т&& &     -->      T&
		Т&& &&    -->      T&&
	
	Грубо говоря lvalue-ссылка всегда побеждает

	Пусть у нас есть шаблонная функция, которая принимает rvalue-ссылку
	
		template <typename T>
		void func(T&& x) {};
		
	Можно ли эту функцию вызвать так:
		func(5);
	А так:
		int a = 10;
		func(a);	
		
	Очевидно, что такая функция может принять rvalue-выражение
	Но также она может принять и lvalue выражение, так как компилятор может подставить
	за место типа T тип int& и в качестве типа получить int& &&
	Затем он свернёт эти ссылки и получит тип int& и сможет принять переменную a по ссылке
	
	rvalue: func(5)               lvalue: func(a) 
	
	T     = int                   T     = int&
	тип x = int&&                 тип x = int&
	
	
	Таким образом такая шаблонная функция может принять на вход и lvalue и rvalue
	Rvalue-ссылки с шаблонной подстановкой называют универсальными ссылками

*/



template <typename T>
void func(T&& x)
{
    cout << "T = " << typeName<T>() << ",\t type of x = " << typeName<decltype(x)>() << endl;
}



int main()
{
    int a = 5;
    func(5);
    func(a);
}


/*
	Проверьте как выведется T, если мы передаём 
		func(std::move(a));
	
	
	Проверьте как выведется T, если мы передаём 
		const int b = 10;
		func(b);
		
	Проверьте как выведется T, если мы передаём 
		const int& c = 10;
		func(c);


*/
