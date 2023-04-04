



#include <iostream>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;
using std::cout, std::endl;


void func()
{
    for (int i = 0; i < 3; ++i)
    {
        cout << i << endl;
        std::this_thread::sleep_for(1s);
    }
}


int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    

    std::thread t{func};
    t.join();


    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;

    cout << elapsed.count() << endl;
}

