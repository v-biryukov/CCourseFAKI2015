#include <iostream>
#include <vector>
#include <list>
using std::cout, std::endl;

int main()
{
    std::list<int>   l {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    std::vector<int> v {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    for (std::list<int>::reverse_iterator rit = l.rbegin(); rit != l.rend(); ++rit)
        cout << *rit << " ";
    cout << endl;


    for (std::vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); rit += 2)
        cout << *rit << " ";
    cout << endl;
}