#include <iostream>
#include <cstdlib>
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
};


int main()
{
    void* p = malloc(sizeof(Verbose));
    Verbose* pa = new(p) Verbose {"Alice"s};
    cout << pa->getName() << endl;
    pa->~Verbose();
    free(p);



    char buffer[sizeof(Verbose)];
    Verbose* pb = new(buffer) Verbose {"Bob"s};
    cout << pb->getName() << endl;
    pb->~Verbose();
}
