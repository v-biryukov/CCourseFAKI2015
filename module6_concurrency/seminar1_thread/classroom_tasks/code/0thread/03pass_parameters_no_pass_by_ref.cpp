/*
    Что если функция потока принимает аргумент по ссылке?

    Важно понимать, что все аргументы, которые вы передаёте в конструктор std::thread
    будут скопированы или перемещены. Даже если функция принимает этот объект по ссылке.

    Например, в этом примере, функция func принимает объект по ссылке.
    Если мы вызовем эту функцию обычным образом:

        func(a);

    то объект передастся по ссылке и никакого копирования/перемещения происходить не будет.


    Но если мы передадим этот объект на вход конструктору std::thread, то он будет либо
    скопирован либо перемещён в зависимости от категории передаваемого выражения.
*/

#include <thread>
#include <iostream>

// Специальный класс, который печатает на экран, когда вызывается его особые методы
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


void func(const Verbose& c)
{
    std::cout << "Inside func (" << c.getName() << ")" << std::endl;
}


int main()
{
    Verbose a {"Alice"};
    func(a);

    // В конструктор объекта t1 передаётся объект a по унивесальной ссылке.
    // Но внутри конструктора объект a копируется, и только потом передаётся в функцию func по ссылке.
    std::cout << std::endl << "Starting t1:" << std::endl;
    std::thread t1(func, a);
    t1.join();


    // В конструктор объекта t2 передаётся объект a по унивесальной ссылке.
    // Но внутри конструктора объект a перемещается, и только потом передаётся в функцию func по ссылке.
    std::cout << std::endl << "Starting t2:" << std::endl;
    std::thread t2(func, std::move(a));
    t2.join();
}
