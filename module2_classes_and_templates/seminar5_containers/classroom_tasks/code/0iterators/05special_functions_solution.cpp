#include <iostream>
#include <list>
using std::cout, std::endl;

int main()
{
    std::list<int> l {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << ' ';
    cout << endl;



    std::list<int>::iterator it = l.begin();
    std::advance(it, 6);
    *it += 5;

    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << ' ';
    cout << endl;
}