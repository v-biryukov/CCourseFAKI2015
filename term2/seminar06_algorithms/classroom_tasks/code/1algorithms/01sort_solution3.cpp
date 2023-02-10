#include <iostream>
#include <vector>
#include <string>
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
    int n;
    cin >> n;

    std::vector<std::string> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];


    printVector(v);
    for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it)
    {
        std::reverse(it->begin(), it->end());
    }

    std::sort(v.begin(), v.end());
    printVector(v);
}