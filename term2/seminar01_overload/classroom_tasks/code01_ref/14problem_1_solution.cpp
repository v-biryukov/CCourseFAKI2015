#include <iostream>
using std::cout, std::endl;


void multiplyBy2(int& a)
{
    a *= 2;
}

int main() 
{
    int x = 10;
    multiplyBy2(x);
    cout << x << endl;
}

