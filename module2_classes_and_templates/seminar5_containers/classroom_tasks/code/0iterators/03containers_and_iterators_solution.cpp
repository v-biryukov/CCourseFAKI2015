#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <list>
using std::cout, std::endl;

int main()
{
    std::list l          {70, 10, 40, 30, 80};
    std::set s           {70, 10, 40, 30, 80};
    std::unordered_set u {70, 10, 40, 30, 80};

    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;

    for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";
    cout << endl;

    for (std::unordered_set<int>::iterator it = u.begin(); it != u.end(); ++it)
        cout << *it << " ";
    cout << endl;

}