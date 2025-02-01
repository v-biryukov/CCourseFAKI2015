#include <iostream>
#include "string.hpp"
using std::cout, std::cin, std::endl;

int main() 
{
    mipt::String a = "Mouse";
    mipt::String b;
    cin >> b;
    mipt::String c = b;

    if (a + c == "MouseLion")
        cout << "Yes" << endl;
    else
        cout << "No" << endl;


    if (a > "Mice")
        cout << "Yes" << endl;
    else
        cout << "No" << endl;


    c[0] = 'P';
    cout << c << endl;

    c += a;
    cout << c << endl;

    c = c + mipt::String(10, 'q');
    cout << c << endl;
}
