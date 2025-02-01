/*




*/

#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;
using std::cout, std::endl;

int data;
bool isReady;

void f1()
{
    data = 123;
    isReady = true;
}


void f2()
{
    if (isReady)
        cout << "data = " << data << '\n';
}



int main()
{

    for (int i = 0; i < 100000; ++i)
    {
        data = 0;
        isReady = false;

        std::thread t1(f1);
        std::thread t2(f2);

        t1.join();
        t2.join();
    }
}