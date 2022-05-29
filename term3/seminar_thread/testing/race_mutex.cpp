#include <iostream>
#include <thread>
#include <mutex>
using std::cout, std::endl;

int a = 0;

std::mutex m;

void inc()
{
    m.lock();
    for (int i = 0; i < 1'000'000; ++i)
    {
        a += 1;
    }
    m.unlock();
}

int main()
{
    std::thread t1 {inc};
    std::thread t2 {inc};

    t1.join();
    t2.join();

    cout << a << endl;
}