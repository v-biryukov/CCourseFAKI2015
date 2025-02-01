#include <iostream>
#include <vector>
using std::cout, std::endl;


void inc(std::vector<int>::iterator start, std::vector<int>::iterator finish)
{
    for (std::vector<int>::iterator it = start; it != finish; ++it)
    {
        (*it)++;
    }
}

int main () 
{
    std::vector<int> v = {54, 62, 12, 97, 41, 62, 73, 10, 59, 92};

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;




    inc(v.begin(), v.end());
    inc(v.begin() + 3, v.end() - 1);

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}