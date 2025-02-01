#include <thread>
#include <iostream>
#include <chrono>
using namespace std::chrono_literals;
using std::cout, std::endl;


int a = 0;


int main()
{
    if (a == 0)
    {
        a++;
        std::thread t(main);

        std::this_thread::sleep_for(5s);
        t.detach();

        cout << "Hello from main" << endl;

        
        return 0;
    }

    cout << "Hello from thread" << endl;
    return 0;
}
