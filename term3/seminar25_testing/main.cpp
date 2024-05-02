#include <iostream>
#include "LinkedList.hpp"


int main()
{
    LinkedList<int> a;

    a.pushFront(10);
    a.pushFront(20);
    a.pushFront(30);
    a.pushBack(40);

    for (LinkedList<int>::iterator it = a.begin(); it != a.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    std::cout << a.popFront() << std::endl;
    std::cout << a.popFront() << std::endl;
    std::cout << a.popFront() << std::endl;
    std::cout << a.popFront() << std::endl;
}