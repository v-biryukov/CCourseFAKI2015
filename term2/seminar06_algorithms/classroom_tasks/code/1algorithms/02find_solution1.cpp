#include <iostream>
#include <vector>
#include <algorithm>
using std::cout, std::cin, std::endl;

template <typename T>
void printVector(const std::vector<T>& v)
{
    for (typename std::vector<T>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}


int main()
{
    std::vector<int> v {81, 82, 78, 36, 39, 96, 11, 58, 15, 48};

    int el;
    cin >> el;

    std::vector<int>::iterator it = std::find(v.begin(), v.end(), el);

    if (it != v.end())
        cout << it - v.begin() << endl;
    else
        cout << "No such element" << endl;

}