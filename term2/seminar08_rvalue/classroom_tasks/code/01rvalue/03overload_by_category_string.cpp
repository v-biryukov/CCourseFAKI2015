/*
    В этом простом примере показывается перегрузка по категории выражения.

*/

#include <iostream>
#include <string>
using std::cout, std::endl;


void func(std::string& s)
{
    cout << "Pass by lvalue reference" << endl;
}

void func(std::string&& s)
{
    cout << "Pass by rvalue reference" << endl;
}

int main()
{
    std::string s1 = "Cat";
    std::string s2 = "Dog";

    func(s1);
    func(s1 + s2);
    func(s1.substr(0, 2));
}