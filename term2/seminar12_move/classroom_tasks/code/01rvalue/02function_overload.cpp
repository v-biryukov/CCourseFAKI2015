#include <iostream>
#include <vector>
using std::cout, std::endl;


void func(int& x)
{
    cout << "Lvalue reference func: x = " << x << endl;
}

void func(int&& x)
{
    cout << "Rvalue reference func: x = " << x << endl;
}


int main()
{
    func(10);

    int a = 20;
    func(a);


    func(a + 0);
    func(+a);
}