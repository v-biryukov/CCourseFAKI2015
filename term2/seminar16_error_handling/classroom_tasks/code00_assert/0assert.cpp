#include <iostream>
#include <cmath>
#include <cassert>
using std::cout, std::endl;


float geometricMean(float a, float b)
{
    assert(a >= 0 && b >= 0);
    return std::sqrt(a * b);
}


int main()
{
    cout << geometricMean(5, 7) << endl;
    cout << geometricMean(-2, 2) << endl;
}