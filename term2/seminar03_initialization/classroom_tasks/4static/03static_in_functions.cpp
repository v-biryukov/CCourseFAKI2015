/*
    Статические переменные в функциях

    Статические переменные в функциях также создаются в сегменте памяти данные.
    Они инициализируются только один раз, при первом входе в функцию и уничтожаются только в самом конце
    (после функции main). Инициализируются они также как и глобальные переменные.
    Получить доступ к таким переменным можно только внутри соответствующей функции.

    По сути, они очень похожи на глобальные переменные, но видимы только внутри одной функции.
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
};


void func()
{
    static Verbose a("Alice");
    static int b = 0;

    b += 10;

    cout << a.getName() << " " << b << endl;
}


int main()
{
    func();
    func();
    func();
}
