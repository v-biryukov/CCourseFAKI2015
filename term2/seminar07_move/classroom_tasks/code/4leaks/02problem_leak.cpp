/*
    Задача:

        Есть ли в данной программе утечка памяти, и, если есть, то где?
*/

#include <iostream>


void func(int n)
{
    int* p = new int[n];
    int* q = new int[n];


    delete [] p;
    delete [] p;
}


int main()
{
    func(100);
}