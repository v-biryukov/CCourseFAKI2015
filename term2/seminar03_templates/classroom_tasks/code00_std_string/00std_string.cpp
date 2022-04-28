#include <iostream>
#include <string>
using std::cout, std::endl;


int main()
{
    std::string s = "Sapere";
    cout << s << endl;

    s += " Aude";
    cout << s << endl;

    std::string s2 = s + "!";
    cout << s2 << endl;
    cout << s2[3] << endl;

    s2[3] = 'X';
    cout << s2;
}


