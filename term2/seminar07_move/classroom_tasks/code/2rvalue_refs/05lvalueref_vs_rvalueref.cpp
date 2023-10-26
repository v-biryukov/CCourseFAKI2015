/*
    Различие между lvalue-ссылками и rvalue-ссылками.

    Как было сказано раньше, различия между lvalue-ссылками и rvalue-ссылками минимальны:
    
        1)  Основное различие заключается в том, что lvalue-ссылки могут инициализироваться только lvalue
        выражениями, а rvalue-ссылки - только rvalue выражениями.
        
        2)  Также lvalue-ссылки и rvalue-ссылки это разные типы, поэтому по ним можно перегружать функции.
*/

#include <iostream>
#include <string>
#include <utility>
using std::cout, std::endl;


void func(int& x)
{
    cout << "lvalue: " << x << endl;
}

void func(int&& x)
{
    cout << "rvalue: " << x << endl;
}

int main()
{
    int a = 10;
    int b = 20;

    int&  l = a;
    int&& r = a + b;

    func(a);
    func(a + b);
    
    func(l);
    func(r);
    func(l + r);
}


/*
    Задача: Что напечатает данная программа?
*/