#include <iostream>
#include <vector>
#include <algorithm>
using std::cout, std::endl;

template <typename T>
void printVector(const std::vector<T>& v)
{
    for (typename std::vector<T>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

bool contains(const std::vector<int>& v, int el)
{
    return std::find(v.begin(), v.end(), el) != v.end();
}


int main()
{
    std::vector<int> v {81, 82, 78, 36, 39, 96, 11, 58, 15, 48};

    cout << std::boolalpha;

    cout << contains(v, 15) << endl;
    cout << contains(v, 20) << endl;
}