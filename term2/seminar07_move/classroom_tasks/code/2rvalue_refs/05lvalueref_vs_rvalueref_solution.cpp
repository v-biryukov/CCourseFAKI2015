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

    func(a);        // lvalue
    func(a + b);    // rvalue
    
    func(l);        // lvalue
    func(r);        // lvalue   у rvalue-ссылки r есть имя и поэтому это lvalue
    func(l + r);    // rvalue
}