/*
    Передача параметров в поток.

    Для передачи параметров функции в другой поток, их нужно просто передать в конструктор объекта типа std::thread.
    Конструктор класса std::thread - это вариативный шаблонный метод, поэтому он может принимать произвольное
    количество аргументов.
*/

#include <thread>
#include <iostream>


void repeat(std::string s, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << s << ' ';
    }
    std::cout << std::endl;
}


int main()
{
    std::thread t(repeat, "Cat", 10);

    t.join();
}
