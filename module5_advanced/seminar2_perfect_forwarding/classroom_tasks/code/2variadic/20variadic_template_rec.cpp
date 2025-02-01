#include <iostream>
using std::cout, std::endl;


template<typename T>
T sum(T first) 
{
    return first;
}

template<typename T, typename... Args>
T sum(T first, Args... args) 
{
    return first + sum(args...);
}

int main() 
{
    cout << sum(4, 8, 15, 16, 23, 42) << endl;
}