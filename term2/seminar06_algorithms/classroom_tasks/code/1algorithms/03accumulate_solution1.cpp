#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using std::cout, std::cin, std::endl;

int main()
{
    int n;
    cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cout << std::accumulate(v.begin(), v.end(), 0ll) << endl;
}