#include <iostream>
using std::cout, std::endl;


template <int n>
void counter() 
{
    for (int i = 0; i < n; ++i)
        cout << i << " ";
    cout << endl;
}

int main() 
{
    counter<10>();
}