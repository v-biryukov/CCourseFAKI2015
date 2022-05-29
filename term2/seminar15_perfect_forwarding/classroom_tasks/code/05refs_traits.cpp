#include <type_traits>
#include <iostream>
#include "type_name.hpp"
using std::cout, std::endl;

/*
    Именнованные rvalue ссылки очень похожи на lvalue ссылки

    После инициализации их очень сложно отличить от обычных переменных
    
    Но всё же это можно сделать с помощью шаблонных функций
    std::is_lvalue_reference и std::is_rvalue_reference
    
    Эти функторы принимают тип аргумента через шаблонный параметр и возвращают
    булевое значение, является ли данный тип lvalue/rvalue ссылкой

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
