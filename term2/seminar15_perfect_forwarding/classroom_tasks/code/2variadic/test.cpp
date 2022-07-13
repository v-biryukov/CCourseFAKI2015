#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
using std::cout, std::endl, std::pair, std::vector;
#include "type_name.hpp"

template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T> v)
{
    out << "{";
    for (const auto& el : v)
        out << v << ", "
    

}


template<typename... Args>
auto sum(Args... args)
{
    return (args + ...);
}


template<typename... Args>
auto print(Args... args)
{
    ((cout << args << " ") , ...);
}



template<typename... Args>
auto printTypes(Args&&... args)
{
    ((cout << typeName<Args>() << ", ") , ...);
}



void call(auto&& Func, auto&&... args)
{
    (Func(args), ...);
}



int main() 
{
    cout << sum(4, 8, 15, 16, 23, 42) << endl;


    int a = 10;
    int& r = a;
    int b[10] = {0};
    printTypes(1, 2.0f, true, a, &a, r, b, sin);
    cout << endl;


    call([](int a){cout << a << endl;}, 1, 2, 3, 4, 5);


    call([](const vector<int>& a){cout << a << ", ";}, vector{1, 2, 3, 4, 5}, "Hello", vector{"Cat", "Dog", "Mouse"});
}