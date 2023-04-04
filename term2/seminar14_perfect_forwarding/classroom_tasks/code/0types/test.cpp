#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <functional>
#include "type_name.hpp"
using std::cout, std::endl;


int sum(int a, int b) {return 12354;};

struct Book 
{
    std::string title;
    int pages;
    float price;

    int print(int x) {return 1;};
};


int main()
{
    int (Book::*p)(int) = &Book::print;

    auto q = std::mem_fn(p);

    cout << typeName<decltype(p)>() << endl;
    cout << typeName<decltype(q)>() << endl;

}