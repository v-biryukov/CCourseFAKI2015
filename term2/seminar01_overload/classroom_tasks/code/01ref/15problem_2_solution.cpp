#include <iostream>
using std::cout, std::endl;

void sumAndSave(int a, int b, int& c)
{
    c = a + b;
}


int main() 
{
    int x = 10, y = 20;
    int z;

    sumAndSave(x, y, z);
    cout << z << endl;


    sumAndSave(70, 80, z);
    cout << z << endl;
}

