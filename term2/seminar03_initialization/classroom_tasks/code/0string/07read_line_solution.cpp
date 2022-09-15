#include <iostream>
#include <string>
using std::cout, std::cin, std::endl;


int main()
{
    std::string a;
    std::getline(cin, a, '.');
    cout << a << endl;
}