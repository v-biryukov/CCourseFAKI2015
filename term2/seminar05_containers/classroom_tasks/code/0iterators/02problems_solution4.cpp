#include <iostream>
#include <vector>
using std::cout, std::endl;


void inc(std::vector<int>& v)
{
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        (*it)++;
    }
}

int main () 
{
    std::vector<int> v = {54, 62, 12, 97, 41, 62, 73, 10, 59, 92};

    inc(v);

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}