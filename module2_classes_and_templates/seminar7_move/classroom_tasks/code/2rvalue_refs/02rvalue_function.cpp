/*
    Таким образом у нас появился новый способ передачи объекта в функцию.
    Передача по rvalue ссылке.

    Важно понимать, что при передаче по rvalue-ссылке никакого перемещения не происходит.
    В функцию просто передаётся ссылка на временный объект.
    При этом время жизни временного объекта продлевается до завершения функции.
*/


#include <iostream>
#include <vector>
using std::cout, std::endl;


void printVectorValue(std::vector<int> v)
{
    for (auto el : v)
        cout << el << " ";
}


void printVectorRef(std::vector<int>& v)
{
    for (auto el : v)
        cout << el << " ";
}

void printVectorConstRef(const std::vector<int>& v)
{
    for (auto el : v)
        cout << el << " ";
}


void printVectorRvalueRef(std::vector<int>&& v)
{
    for (auto el : v)
        cout << el << " ";
}


int main()
{
    printVectorRvalueRef(std::vector<int>{10, 20, 30, 40, 50});
}