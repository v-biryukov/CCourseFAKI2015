#include <iostream>
#include <string>
#include <vector>
#include <any>
#include <variant>
#include <functional>
#include <stdexcept>
#include <memory>
using std::cout, std::endl;
using namespace std::string_literals;

void func1(int& l)
{
    cout << "Lvalue" << endl;
}

void func1(int&& r)
{
    cout << "Rvalue" << endl;
}


template <typename T>
void func2(T&& r)
{
    func1(std::forward<T>(r));
}

int main()
{
    int a = 100;

    func2(a); // T = int&
    func2(200);
}