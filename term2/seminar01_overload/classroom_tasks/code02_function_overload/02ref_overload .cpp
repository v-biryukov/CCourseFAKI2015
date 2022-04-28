#include <iostream>
using std::cout, std::endl;

/*
    В отличии от C, в C++ можно создать несколько функций с одним и тем же названием, 
    но с разными типами аргументов
*/


void func(int x) 
{
    cout << "int x" << endl;
}
    

void func(const int& x) 
{
    cout << "int& x" << endl;
}




int main() 
{
    func(5);

    int a = 10;
    func(a);

}