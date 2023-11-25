/*
    std::initializer_list

*/


#include <iostream>
#include <initializer_list>
#include <utility>
#include <vector>
#include <string>
#include <array>
using std::cout, std::endl, std::string, std::pair;


template <typename T>
void func(std::initializer_list<T> elems)
{
    for (const T& el : elems)
    {
        cout << el << " ";
    }
    cout << endl;
}


int main()
{
    func({10, 20, 30, 40, 50});
    func({"Cat", "Dog", "Lion"});
}

