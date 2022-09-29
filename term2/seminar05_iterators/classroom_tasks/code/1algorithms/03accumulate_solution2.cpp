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

    int k;
    cin >> k;

    std::partial_sort(v.begin(), v.begin() + k, v.end());
    cout << std::accumulate(v.begin(), v.begin() + k, 0ll) << endl;
}