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


template <typename T>
T max(const std::vector<T>& v)
{
    T result {v[0]};

    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] > result)
            result = v[i];
    }

    return result;
}


int main()
{
    std::vector v1 {10, 20, 30, 40, 50};
    std::vector v2 {1.5, 6.1, -0.5, 2.4, -4.7};
    std::vector<std::string> v3 {"Cat", "Dog", "Mouse", "Elephant"};

    cout << max(v1) << endl;
    cout << max(v2) << endl;
    cout << max(v3) << endl;
}



