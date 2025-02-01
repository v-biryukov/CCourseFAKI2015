#include <iostream>
#include <vector>
#include <string>
using std::cout, std::endl;

int main()
{
    std::vector<std::string> v {"Cat", "Dog", "Mouse", "Lion"};

    for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;
}