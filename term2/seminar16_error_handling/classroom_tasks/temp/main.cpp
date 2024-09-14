#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using std::cout, std::endl;

class Verbose
{
private:
    std::string mName   {};

public:
    Verbose()   {std::cout << "Default Constructor (" << mName << ")" << std::endl;}
    ~Verbose()  {std::cout << "Destructor ("          << mName << ")" << std::endl;}
    Verbose(const std::string& name) : mName{name}
    {
        std::cout << "Constructor from std::string (" << mName << ")" << std::endl;
    }

    Verbose(const char* name) : mName{name} 
    {
        std::cout << "Constructor from const char* (" << mName << ")" << std::endl;
    }

    Verbose(const Verbose& v) : mName{v.mName} 
    {
        std::cout << "Copy Constructor (" << mName << ")" << std::endl;
    }

    Verbose& operator=(const Verbose& v)
    {
        mName = v.mName;
        std::cout << "Copy Assignment Operator (" << mName << ")" << std::endl;
        return *this;
    }

    Verbose(Verbose&& v) : mName{std::move(v.mName)} 
    {
        std::cout << "Move Constructor (" << mName << ")" << std::endl;
    }

    Verbose& operator=(Verbose&& v)
    {
        mName = std::move(v.mName);
        std::cout << "Move Assignment Operator (" << mName << ")" << std::endl;
        return *this;
    }

    std::string getName() const {return mName;}
};





int divide(int a, int b)
{
    std::vector<int> v(1000);

    if (b == 0)
    {
        throw std::runtime_error("Division by zero");
    }

    return a / b;
}


template <typename T>
int foo(T x) noexcept(noexcept(x = T{}))
{
    T a;
    return 123;
}




void bar()
{
    int* p = new int();


    delete p;
}


int main()
{
    foo<int>(1);
    foo<std::string>("Cat");

    try
    {
        bar();
    }
    catch(std::exception& x)
    {
        cout << "Error: " << x.what() << endl;
    }
}

