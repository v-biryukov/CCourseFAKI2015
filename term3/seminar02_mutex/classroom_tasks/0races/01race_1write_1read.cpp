/*
    Пишем в одном потоке, а читаем в другом. Это неопределённое поведение!

    Убедитесь в этом, скомпилировав и запустив эту программу с разными уровнями оптимизации (без оптимизаций и -O3)
*/


#include <thread>
#include <iostream>
#include <chrono>
#include <atomic>
using namespace std::chrono_literals;
using std::cout, std::endl;


int a = 0;


void func1()
{
    while (true)
    {
        a += 1;
    }
}


void func2()
{
    while (true)
    {
        std::cout << a << endl;
    }
}


int main()
{
    std::thread t1(func1);
    std::thread t2(func2);

    t1.join();
    t2.join();
}