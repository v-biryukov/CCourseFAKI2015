#include <iostream>

struct Test 
{
    int val;

    void hello() 
    {
        std::cout << "Hello\n";
    }
};



template <typename T>
void func(T a) 
{
    a.hello();
}


int main() 
{
    Test t;
    func(t);
}