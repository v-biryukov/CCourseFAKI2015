/*
    Задача:

        Что напечатает данная программа?
        Попробуйте догадаться до этого без запуска программы.
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


void take(Verbose x)
{
    cout << x.getName() << endl;
}


int main()
{
    take(Verbose(Verbose(Verbose(Verbose(Verbose(Verbose(Verbose(Verbose(Verbose(Verbose(Verbose{"Alice"s})))))))))));

}