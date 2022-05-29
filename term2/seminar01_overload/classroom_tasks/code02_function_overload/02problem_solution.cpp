#include <iostream>
using std::cout, std::endl;


int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

double max(double a, double b)
{
    if (a > b)
        return a;
    else
        return b;
}

int max(int a, int b, int c)
{
    int result = a;
    if (b > result)
        result = b;
    if (c > result)
        result = c;
    return result;
}

double max(double a, double b, double c)
{
    double result = a;
    if (b > result)
        result = b;
    if (c > result)
        result = c;
    return result;
}




int main() 
{
    cout << max(4.2, 2.8) << endl;

    cout << max(1, 2) << endl;

    cout << max(4, 2, 5) << endl;

    cout << max(1.2, 2.1, 0.5) << endl;
}