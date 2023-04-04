/*
    Пишем в разные биты переменной. Это неопределённое поведение!

    Убедитесь в этом, скомпилировав и запустив эту программу с разными уровнями оптимизации (без оптимизаций и -O3)
*/


#include <thread>
#include <iostream>
#include <chrono>
#include <atomic>
using namespace std::chrono_literals;
using std::cout, std::endl;


uint64_t a = 0;


void func1()
{
    for (int i = 0; i < 0x100000; ++i)
        a += 0x1;
}


void func2()
{
    for (int i = 0; i < 0x100000; ++i)
        a += 0x1000000;
}


int main()
{
    std::thread t1(func1);
    std::thread t2(func2);

    t1.join();
    t2.join();


    cout << std::hex << a << endl;
}