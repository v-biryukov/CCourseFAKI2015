#include <iostream>
#include <string>
#include <thread>
using std::cout, std::endl, std::thread;

std::string s {};

void inc(char c)
{
    for (int i = 0; i < 100'000; ++i)
    {
        s += c;
    }
}

int main()
{
    thread t1 {inc, 'a'};
    thread t2 {inc, 'b'};

    t1.join();
    t2.join();

    cout << s << endl;
}