#include <iostream>
#include <vector>
#include <algorithm>
using std::cout, std::cin, std::endl;

int main()
{
    int n;
    cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    std::vector<int>::iterator it = std::min_element(v.begin(), v.end());
    cout << *it << " " << it - v.begin() << endl;
}