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
    func({10, 20, 30, 40, 50});
}