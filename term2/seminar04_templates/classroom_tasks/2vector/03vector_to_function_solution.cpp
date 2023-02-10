#include <iostream>
#include <vector>
#include <string>
using std::cout, std::endl;

void printVector(const std::vector<int>& v)
{
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}

void inc(std::vector<int>& v)
{
    for (int i = 0; i < v.size(); ++i)
        v[i]++;
}

int sum(const std::vector<int>& v)
{
    int result = 0;
    for (int i = 0; i < v.size(); ++i)
        result += v[i];
    return result;
}

std::vector<int> createArithmetic(int start, int d, int n)
{
    std::vector<int> result(n);

    for (int i = 0; i < n; ++i)
        result[i] = start + d * i;

    return result;
}


std::vector<int>& operator+=(std::vector<int>& v, int a)
{
    for (int i = 0; i < v.size(); ++i)
        v[i] += a;
    return v;
}


int main()
{
    std::vector<int> v {10, 20, 30, 40, 50};
    printVector(v);

    inc(v);
    printVector(v);

    cout << sum(v) << endl;

    v = createArithmetic(100, 5, 20);
    printVector(v);

    v += 2;
    printVector(v);

}