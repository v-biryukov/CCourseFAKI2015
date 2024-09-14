#include <iostream>
using std::cout, std::endl;

class Functor 
{
public:
    void operator()() 
    {
        cout << "Functor operator() call" << endl;
    }
};

int main() 
{
    Functor f;
    f();
}