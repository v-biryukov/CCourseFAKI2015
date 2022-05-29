#include <iostream>
using std::cout, std::endl;


void cubeByPointer(int* p)
{
    *p = *p * *p * *p;
}

void cubeByReference(int& a)
{
    a = a * a * a;
}


void swapByPointer(int* pa, int* pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void swapByReference(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}



int main() 
{
    int a = 5;
    cubeByPointer(&a);
    cout << a << endl;

    a = 5;
    cubeByReference(a);
    cout << a << endl;



    int x = 10, y = 20;
    swapByPointer(&x, &y);
    cout << x << " " << y << endl;


    x = 10; 
    y = 20;
    swapByReference(x, y);
    cout << x << " " << y << endl;

}