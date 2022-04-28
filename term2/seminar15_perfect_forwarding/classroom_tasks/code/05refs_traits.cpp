#include <typeinfo>
#include <type_traits>
#include <string>
#include <vector>
#include <iostream>
using std::cout, std::endl;
#include "type_name.hpp"

/*
    Именнованные rvalue ссылки очень похожи на lvalue ссылки

    Различие есть в инициализации таких ссылок, но по

*/




int main()
{
    int a = 5;
    int&  r1 = a;
    int&& r2 = 10;


    cout << "a is lvalue ref? " <<  std::is_lvalue_reference<decltype(a)>() << endl;
    cout << "a is rvalue ref? " <<  std::is_rvalue_reference<decltype(a)>() << endl << endl;

    cout << "r1 is lvalue ref? " <<  std::is_lvalue_reference<decltype(r1)>() << endl;
    cout << "r1 is rvalue ref? " <<  std::is_rvalue_reference<decltype(r1)>() << endl << endl;

    cout << "r2 is lvalue ref? " <<  std::is_lvalue_reference<decltype(r2)>() << endl;
    cout << "r2 is rvalue ref? " <<  std::is_rvalue_reference<decltype(r2)>() << endl;
}