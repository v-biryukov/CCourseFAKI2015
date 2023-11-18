/*
    Copy elision применяется и в других ситуациях, а не только при возврате из функции.

    Copy elision применяется и при передаче в функцию временного объекта.
    В данном примере, в строке

        take(Verbose{"Alice"});

    кажется, что создаётся временный объект Verbose{"Alice"} c помощью конструктора от std::string,
    а потом этот временный объект копируется в функцию take с помощью конструктора копирования.

    На самом деле объект сразу создаётся в памяти функции take.
    Таким образом копирования не происходит.
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
    take(Verbose{"Alice"s});

}