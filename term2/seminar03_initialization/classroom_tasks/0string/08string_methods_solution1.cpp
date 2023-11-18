#include <iostream>
#include <string>
using std::cout, std::cin, std::endl;

bool isCom(std::string& s)
{
    return s.starts_with("www.") && s.ends_with(".com");
}


int main()
{
    std::string str;
    cin >> str;
    cout << std::boolalpha << isCom(str) << endl;
}