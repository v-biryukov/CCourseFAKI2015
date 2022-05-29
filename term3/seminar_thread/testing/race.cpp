#include <iostream>
#include <thread>
using std::cout, std::endl, std::thread;

int a = 0;

void inc()
{
    for (int i = 0; i < 1'000'000; ++i)
    {
        a += 1;
    }
}

int main()
{
    thread t1 {inc};
    thread t2 {inc};

    t1.join();
    t2.join();

    cout << a << endl;
}