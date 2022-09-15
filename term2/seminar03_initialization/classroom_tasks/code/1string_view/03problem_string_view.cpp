#include <iostream>
#include <string>
#include <string_view>
using std::cout, std::cin, std::endl;


std::string_view func()
{
    std::string a = "Cat and Dogs";
    return a;
}


int main()
{
    cout << func() << endl;
}


/*
    Задача:
        
        Является ли данная программа корректной?
        Что если увеличить размер строки так, чтобы он не влезал в буфер малой строки?

*/