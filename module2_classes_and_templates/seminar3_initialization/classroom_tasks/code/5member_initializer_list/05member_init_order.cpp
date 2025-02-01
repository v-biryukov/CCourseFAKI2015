/*
    Порядок инициализации значений

    Класс Test содержит три поля типа Verbose: ma, mb и mc.
    
    В классе они объявлены в таком порядке: первый ma, потом mb, третий mc.
    В списке инициализации они инициализируются так: первый mc, потом mb, третий ma.

    Задача:
    
        В каком порядке будут инициализированы поля класса Test?
        Запустите программу и узнайте ответ.

        Почему поля инициализируются в таком порядке?
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
};


int main()
{
    Test t;
}