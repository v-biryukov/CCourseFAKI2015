/*
    Компиляция:

        g++ main.cpp string.cpp

*/

#include <iostream>
#include "string.hpp"
using std::cout, std::cin, std::endl;

int main() 
{
    String a = "Mouse";
    String b;
    cin >> b;
    String c = b;

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

    c = c + String(10, 'q');
    cout << c << endl;
}
