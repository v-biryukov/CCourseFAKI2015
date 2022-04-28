#include <iostream>
using std::cout, std::endl;

class Functor 
{
private:
    int mCount;
public:

    Functor() 
    {
        mCount = 0;
    }

    void operator()() 
    {
        mCount += 1;
        cout << "Functor call # " << mCount << endl;
    }
};

int main() 
{
    Functor f;
    for (int i = 0; i < 10; ++i)
        f();
}