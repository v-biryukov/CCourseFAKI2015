/*
    Copy elision применяется не при каждом возврате из функции.

    Например, если мы возвращаем объект, который является параметром функции, то copy elision не работает.

    В этом примере программе придётся копировать объект сначала в функцию takeAndReturn, а затем
    придётся копировать тот же самый объект из этой функции в функцию main.
*/

#include <iostream>
#include <string>
using std::cout, std::endl;
using namespace std::string_literals;

class Verbose
{
private:
    std::string mName {};
public:
    Verbose()   {std::cout << "Default Constructor (" << mName << ")" << std::endl;}
    ~Verbose()  {std::cout << "Destructor (" << mName << ")" << std::endl;}
    Verbose(const std::string& name) : mName(name)    {std::cout << "Constructor from std::string (" << mName << ")" << std::endl;}
    Verbose(const Verbose& v)        : mName(v.mName) {std::cout << "Copy Constructor (" << mName << ")" << std::endl;}
    std::string getName() const {return mName;}
    Verbose& operator=(const Verbose& v)
    {
        mName = v.mName;
        std::cout << "Copy Assignment Operator (" << mName << ")" << std::endl;
        return *this;
    }
};


Verbose takeAndReturn(Verbose x)
{
    cout << x.getName() << endl;
    return x;
}


int main()
{
    Verbose a {"Alice"s};
    Verbose b = takeAndReturn(a);
}