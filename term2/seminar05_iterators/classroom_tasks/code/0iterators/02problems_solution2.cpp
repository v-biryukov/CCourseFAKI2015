#include <iostream>
#include <vector>
using std::cout, std::endl;


int main () 
{
    std::vector<int> v = {54, 62, 12, 97, 41, 62, 73, 10, 59, 92};

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it += 2)
    {
        cout << *it << " ";
    }
    cout << endl;
}