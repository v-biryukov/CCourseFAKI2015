/*
    В отличии от языка C в языке C++ стандартные математические функции уже перегружены и могут
    работать с разными типами данных
*/

#include <iostream>
#include <cmath>
using std::cout, std::endl;



int main() 
{
    cout << std::abs(-4) << endl;
    cout << std::abs(-4.2) << endl;
    cout << std::abs(-4.2f) << endl;
}