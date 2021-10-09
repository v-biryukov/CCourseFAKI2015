#include <iostream>
#include <string>

using std::cout;
using std::endl;


int main()
{
    std::pair<std::string, int> p {"Cat", 50};

    cout << "First: " << p.first << ". Second: " << p.second << endl; 
}