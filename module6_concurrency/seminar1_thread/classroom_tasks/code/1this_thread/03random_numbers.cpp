#include <random>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::mt19937 e {std::random_device{}()};
    std::uniform_int_distribution<int> dist {1, 1'000'000};


    std::vector<int> numbers(10);
    for (auto& el : numbers)
        el = dist(e);
    

    for (auto el : numbers)
        cout << el << " ";
    cout << endl;
}