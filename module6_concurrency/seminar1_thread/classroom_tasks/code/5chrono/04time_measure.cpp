#include <iostream>
#include <thread>
#include <chrono>


int main()
{
    std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();

    int x = 0;
    for (int i = 0; i < 1'000'000; ++i)
    {
        x += 1;
    }
    std::cout << "x = " << x << std::endl;

    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << " microseconds" << std::endl;
}