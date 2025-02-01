/*
    Создание потоков, используя различные функциональные объекты.

    Создавать поток можно передав в конструктор любой функциональный объект, а не только функции.
    В этом примере создаём новые потоки, используя:

        -   функцию func (t1)
        -   функтор - объект класса Functor (t2)
        -   лямбда-функцию (t3)
        -   лямбда-функцию с захватом (t4)

    Можно также создавать потоки, передав ему указатель на метод.
*/

#include <thread>
#include <iostream>


void func()
{
    std::cout << "Hello from thread" << std::endl;
}


class Functor
{
public:
    void operator()()
    {
        std::cout << "Hello from functor object" << std::endl;
    }
};


int main()
{
    std::thread t1(func);
    t1.join();

    std::thread t2(Functor{});
    t2.join();

    std::thread t3([]() {std::cout << "Hello from lambda function" << std::endl;});
    t3.join();

    int a = 100;
    std::thread t4([a]() {std::cout << "Hello from another lambda, a = " << a << std::endl;});
    t4.join();
}