#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::cout, std::endl;

template <typename T>
void printVector(const std::vector<T>& v)
{
    for (typename std::vector<T>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
        cout << *it << " ";
    cout << endl;
}

template <typename T>
void append(std::vector<T>& a, const std::vector<T>& b)
{
    std::copy(b.begin(), b.end(), std::back_inserter(a));
}


int main()
{
    std::vector<int> a { 4, 8, 15, 16, 23, 42 };
    printVector(a);

    append(a, {10, 20, 30});
    printVector(a);

    append(a, {700});
    printVector(a);
}