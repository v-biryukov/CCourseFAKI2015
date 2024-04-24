/*
    Задача:

        В данном примере написана функция getMax, которая находит максимум из чисел в векторе.
        При этом вычисления проходят однопоточно.


        Вам нужно написать функцию     

            uint64_t getMaxPar(int n, const std::vector<uint64_t>& v)

        которая будет делать то же самое, но только использовать для этого n потоков.
*/

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include <cstdint>
using std::cout, std::endl, std::size_t;
using namespace std::chrono_literals;


uint64_t getMax(const std::vector<uint64_t>& v)
{
    uint64_t result = v.at(0);
    for (auto el : v)
    {
        if (el > result)
            result = el;
    }
    return result;
}


int main()
{
    cout << "Generating numbers!" << endl;
    std::vector<uint64_t> numbers(5e8);
    numbers[0] = 123456789;
    for (size_t i = 1; i < numbers.size(); ++i)
    {
        numbers[i] = numbers[i - 1] * i + 1;
    }
    cout << "Numbers generated!" << endl;


    auto start = std::chrono::high_resolution_clock::now();

    uint64_t m = getMax(numbers);
    cout << "Maximum = " << m << endl;

    auto end = std::chrono::high_resolution_clock::now();
    cout << "Time to calclulate max = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
         << " milliseconds." << endl;
}