#include <iostream>
using std::cout, std::endl;


int main() 
{
    int a[5] = {10, 20, 30, 40, 50};

    int& r = a[1];
    r += 1;

    for (int i = 0; i < 5; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;


    int& r2 = a[4];
    r2 *= 2;

    for (int i = 0; i < 5; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}