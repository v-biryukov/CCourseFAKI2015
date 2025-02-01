#include <iostream>
#include <thread>
#include <chrono>

template <typename Unit = std::chrono::microseconds, typename Clock = std::chrono::high_resolution_clock>
class Timer {
    typename Clock::time_point mTick{Clock::now()};

public:

    void tick(){
        mTick = Clock::now();
    }

    std::chrono::milliseconds::rep tock() {
        auto time = std::chrono::duration_cast<Unit>(Clock::now() - mTick).count();
        return time;
    }

    void print() {
        auto time = tock();
        std::cout << "Time difference = " << time << std::endl; 
    }
};



int main()
{
    Timer t;

    int x = 0;
    for (int i = 0; i < 1'000'000; ++i)
    {
        x += 1;
    }
    std::cout << "x = " << x << std::endl;

    auto time = t.tock();
    std::cout << "Time difference = " << time << " microseconds" << std::endl;
}