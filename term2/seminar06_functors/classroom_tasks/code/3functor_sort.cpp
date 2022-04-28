#include <iostream>
#include <vector>
#include <algorithm>
using std::cout, std::endl, std::vector;


class Compare 
{
public:
    bool operator()(int a, int b) 
    {
        return a % 10 > b % 10;
    }
};

std::ostream& operator<<(std::ostream& stream, const vector<int>& right) 
{
    for (size_t i = 0; i < right.size(); ++i)
        cout << right[i] << " ";
    return stream;
}

int main() 
{
    vector<int> v {65, 43, 26, 74, 6, 72, 84, 1, 4, 63, 74};
    cout << v << endl;

    std::sort(v.begin(), v.end(), Compare());
    cout << v << endl;
}