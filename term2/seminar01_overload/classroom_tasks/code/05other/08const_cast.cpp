/*
    const_cast используется для снятия квалификатора const

*/

#include <iostream>

void test(const int* p)
{
    int* q = const_cast<int*>(p);
    *q += 20;
}


void test_ref(const int& p)
{
    int& q = const_cast<int&>(p);
    q += 20;
}


int main()
{
    int a = 100;
    test(&a);
    std::cout << a << std::endl;

    test_ref(a);
    std::cout << a << std::endl;
}