/*
    Задача:

        В данном примере написана функция шаблонная getMax, которая находит максимум из чисел в некотором контейнере.
        При этом вычисления проходят однопоточно.


        Вам нужно написать шаблонную функцию     
            
            template <typename RandIt>
            RandIt getMax(int n, RandIt start, RandIt finish)

        которая будет делать то же самое, но только использовать для этого n потоков.
        Функция должна принимать на вход количество потоков и два итератора, задающих
        диапазон на котором нужно искать максимум.
        Известно, что оба итератора являются random access итераторами.



        Проверить, что эта функция будет работать и для других контейнеров и типов хранящихся в них данных.
        Например, для:

            std::deque<double> d {1.2, 5.1, 8.2, 1.0, 0.2, 5.0, 7.8};
*/








#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <list>
#include <random>
#include <algorithm>
#include <cstdint>
using std::cout, std::endl, std::size_t;
using namespace std::chrono_literals;



template <typename RandIt>
RandIt getMax(RandIt start, RandIt finish)
{
    RandIt maxIt = start;
    for (auto it = start; it != finish; ++it)
    {
        if (*it > *maxIt)
            maxIt = it;
    }
    return maxIt;
}


int main()
{
    cout << "Generating numbers!" << endl;
    std::deque<uint64_t> numbers;
    for (size_t i = 0; i < 1e7; ++i)
    {
        numbers.push_back(numbers.back() * i + 1);
    }
    cout << "Numbers generated!" << endl;




    auto start = std::chrono::high_resolution_clock::now();


    auto it = getMax(numbers.begin(), numbers.end());
    cout << "Maximum = " << *it << endl;


    auto end = std::chrono::high_resolution_clock::now();
    cout << "Time to calclulate max = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
         << " milliseconds." << endl;
}