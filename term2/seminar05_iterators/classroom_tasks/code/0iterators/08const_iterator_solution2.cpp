#include <iostream>
#include <vector>
#include <list>
using std::cout, std::endl;


int sum(const std::list<int>& a)
{
    int result = 0;
    for (std::list<int>::const_iterator it = a.cbegin(); it != a.cend(); ++it)
    {
        result += *it;
    }
    return result;
}

int main()
{
    std::list<int> l {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    cout << sum(l) << endl;
    cout << sum({4, 8, 15, 16, 23, 42}) << endl;

}