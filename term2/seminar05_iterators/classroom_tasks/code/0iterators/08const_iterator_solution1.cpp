#include <iostream>
#include <vector>
using std::cout, std::endl;

int main()
{
    const std::vector<int> v {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};


    for (std::vector<int>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}
