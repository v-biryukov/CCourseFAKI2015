/*
    Что если функция потока принимает аргумент по ссылке?
    И мы хотим 
    
*/

#include <thread>
#include <iostream>
#include <functional>

int main()
{
    int a = 100;

    std::reference_wrapper<int> r = a;
    r.get() += 100;
    std::cout << a << std::endl;

    std::reference_wrapper<int> rcopy = r;
    rcopy.get() += 100;
    std::cout << a << std::endl;
}
