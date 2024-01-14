#include <iostream>
#include <vector>
#include <string>
using std::cout, std::endl;

int main()
{
    std::vector<std::string> v {"Cat", "Dog", "Mouse", "Lion"};

    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}