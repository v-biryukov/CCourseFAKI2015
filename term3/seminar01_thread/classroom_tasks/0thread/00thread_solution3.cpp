#include <thread>
#include <iostream>
using std::cout, std::endl;


void second()
{
    cout << "Hello from thread second" << endl;
}



void first()
{
    cout << "Hello from thread first" << endl;

    std::thread t(second);

    t.join();
}


int main()
{
    std::thread t(first);

    cout << "Hello from main" << endl;

    t.join();
}