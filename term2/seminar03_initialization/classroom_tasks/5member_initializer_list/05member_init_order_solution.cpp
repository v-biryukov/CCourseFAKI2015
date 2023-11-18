/*
    Порядок инициализации значений

    Решение:
    
        Поля инициализируются в том порядке, в котором они объявлены.

        Причина 
*/

#include <iostream>
#include <string>
using std::cout, std::endl;


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


class Test
{
private:

    Verbose ma;
    Verbose mb;
    Verbose mc;

public:

    Test() : mc{"Casper"}, mb{"Bob"}, ma{"Alice"}
    {
    }

    Test(int x) : mb{"Bob"}, ma{"Alice"}, mc{"Casper"}
    {
    }
};


int main()
{
    Test x{};
    Test y{1};
}