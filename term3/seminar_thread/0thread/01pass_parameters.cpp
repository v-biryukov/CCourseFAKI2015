/*
    Передача параметров в поток

    Для передачи параметров функции в другой поток, их нужно просто передать в конструктор объекта типа std::thread.
*/

#include <thread>
#include <iostream>
using std::cout, std::endl;


void repeat(std::string s, int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << s << ' ';
    }
    cout << endl;
}


int main()
{
    std::thread t(repeat, "Cat", 10);

    t.join();
}
