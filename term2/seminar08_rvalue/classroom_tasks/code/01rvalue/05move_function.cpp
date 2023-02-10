#include <iostream>
using std::cout, std::endl;

void funcValue(int x)
{
    x += 1;
}

void funcRvref(int&& x)
{
    x += 1;
}


int main()
{
    int a = 123;

    // При передаче по значению - происходит перемещение
    funcValue(std::move(a));

    // При передаче через rvalue-ссылку, происходит передача по ссылке
    funcRvref(std::move(a));

    cout << a << endl;
}