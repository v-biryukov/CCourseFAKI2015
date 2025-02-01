#include <iostream>
#include <vector>
#include <algorithm>
using std::cout, std::endl;

template <typename T>
void printVector(const std::vector<T>& v)
{
    for (typename std::vector<T>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main()
{
    std::vector<int> v {81, 82, 78, 36, 39, 96, 11, 58, 15, 48};

    printVector(v);
    std::sort(v.begin(), v.end(), [](int a, int b) {return a % 10 < b % 10;});
    printVector(v);
}