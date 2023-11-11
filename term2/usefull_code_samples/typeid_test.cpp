#include <iostream>
#include <type_traits>
using std::cout, std::endl;

struct Base { virtual ~Base() {};};
struct Derived : Base { virtual ~Derived() {};};


int main()
{
    int a = 123;
    int& b = a;


    cout << std::is_same<decltype(a), decltype(b)>::value << endl;
    cout << (typeid(a) == typeid(b)) << endl;
}