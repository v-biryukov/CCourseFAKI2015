#include <iostream>
#include <set>
using std::cout, std::endl;




int main()
{
    std::set<int> s {50, 10, 20, 90, 40, 30, 80, 70, 60};

    for (std::set<int>::iterator it = s.begin(); it != s.end; ++it)
        cout << *it << " ";
    cout << endl;
}