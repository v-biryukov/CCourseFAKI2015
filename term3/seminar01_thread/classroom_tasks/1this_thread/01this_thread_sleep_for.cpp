



#include <iostream>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;
using std::cout, std::endl;


void func()
{
    for (int i = 0; i < 20; ++i)
    {
        cout << i << endl;
        std::this_thread::sleep_for(1s);
    }
}


int main()
{
    std::thread t1{func};
    
    std::this_thread::sleep_for(0.1s);

    std::thread t2{func};


    t1.join();
    t2.join();
}

