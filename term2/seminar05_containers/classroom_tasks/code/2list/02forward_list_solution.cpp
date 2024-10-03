#include <iostream>
#include <forward_list>
#include <string>
using std::cout, std::endl;

int main()
{
    std::forward_list<int> l {10, 20, 30, 40, 50, 60, 70};
    for (std::forward_list<int>::iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;


    // Способ 1:
    std::forward_list<int>::iterator it = l.begin();
    std::size_t n = 0;
    while (it != l.end())
    {
        n++;
        it++;
    }
    cout << "Number of elements = " << n << endl;



    // Способ 2:
    cout << "Number of elements = " << std::distance(l.begin(), l.end()) << endl;
}