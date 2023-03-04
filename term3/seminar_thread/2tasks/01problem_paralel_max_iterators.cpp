/*
    Задача:

        В данном примере написана функция шаблонная getMaxId, которая находит максимум из чисел в векторе.
        При этом вычисления проходят однопоточно.


        Вам нужно написать шаблонную функцию     

            size_t getMaxIdPar(int n, RandIt start, RandIt finish)

        которая будет делать то же самое, но только использовать для этого n потоков.
        Проверить, что эта функция будет работать и для других контейнеров и типов хранящихся в них данных.
        Например, для:

            std::deque<double> d {1.2, 5.1, 8.2, 1.0, 0.2, 5.0, 7.8};
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



template <typename RandIt>
size_t getMaxId(RandIt start, RandIt finish)
{
    RandIt maxIt = start;
    for (auto it = start; it != finish; ++it)
    {
        if (*it > *maxIt)
            maxIt = it;
    }
    return maxIt - start;
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


    size_t id = getMaxId(numbers.begin(), numbers.end());
    cout << "Maximum = " << numbers[id] << endl;


    auto end = std::chrono::high_resolution_clock::now();
    cout << "Time to calclulate max = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
         << " milliseconds." << endl;
}