#include <iostream>
#include <cmath>
using std::cout, std::endl;


void inc(int& x)
{
    x += 1;
}

void normalize(float& x, float& y)
{
    float norm = std::sqrt(x * x + y * y);
    x /= norm;
    y /= norm;
}


int main() 
{
    int a = 5;
    inc(a);
    cout << a << endl;

    float x = 9, y = 6;
    normalize(x, y);
    cout << x << " " << y << endl;
}