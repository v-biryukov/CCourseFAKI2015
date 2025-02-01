#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;
using std::cout, std::endl;

int x;
int y;

int a1;
int a2;


void f1()
{
    std::this_thread::sleep_for(20ms);

    x = 1000;

    a1 = y;
}


void f2()
{
    std::this_thread::sleep_for(20ms);
    
    y = 1000;

    a2 = x;
}



int main()
{

    for (int i = 0; i < 100000; ++i)
    {
        x = 0;
        y = 0;

        std::thread t1(f1);
        std::thread t2(f2);

        t1.join();
        t2.join();

        if (a1 == 0 && a2 == 0)
            cout << a1 << " " << a2 << endl;
    }
}