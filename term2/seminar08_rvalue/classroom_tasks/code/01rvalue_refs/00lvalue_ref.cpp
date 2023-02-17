/*
    lvalue-ссылки

    Обычные ссылки также называются lvalue-ссылками.
    Такие ссылки могут инициализироваться только lvalue выражениями, но не могут инициализироваться rvalue выражениями.

    Константные lvalue-ссылки могут "привязываться" и к lvalue и rvalue выражениям.
*/



#include <iostream>
using std::cout, std::endl;

int main()
{
    int a = 10;

    int& r1 = a;    // OK
    int& r2 = 20;   // Error

    const int& cr1 = a;    // OK
    const int& cr2 = 20;   // OK
}