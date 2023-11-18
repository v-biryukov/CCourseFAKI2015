/*
    Оператор new

    С помощью оператора new можно сразу инициализировать объект нужным образом.
    Для этого нужно передать аргументы для инициализации в круглых или фигурных скобках.
*/

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
    int* pa = new int;          //  Default-инициализация, *pa будет иметь произвольное значение
    int* pb = new int{};        //  Value-инициализация, *pb будет равно нулю
    int* pc = new int{10};      //  Direct-инициализация, *pc будет задано значением 10 

    cout << *pa << endl;
    cout << *pb << endl;
    cout << *pc << endl;

    delete pa;
    delete pb;
    delete pc;



    Verbose* pd = new Verbose;           //  Default-инициализация, вызовется конструктор по умолчанию
    Verbose* pe = new Verbose{};         //  Value-инициализация, вызовется конструктор по умолчанию
    Verbose* pf = new Verbose{"Alice"s}; //  Direct-инициализация, вызовется конструктор с подходящим набором параметоров,
                                         //  то есть конструктор Verbose(const std::string& name).
    


    delete pd;
    delete pe;
    delete pf;
}




/*
    Задачи:

        1)  Что напечатает данная программа? В каком порядке вызовутся деструкторы?

        2)  Создайте объект типа Verbose в куче с помощью конструктора копирования из объекта *pf.
*/