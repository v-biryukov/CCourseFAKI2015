/*
    Copy initialization

    Выглядит вот так:

        type a = {arg1, ...};    или     type a = type{arg1, ...};   или     type a = type(arg1, ...);   

    или если аргумент один, то можно опустить скобки: 

        type a = arg; 

    Также выполняется при передаче в функцию и может выполняться при возврате из функции:

        func({arg1, ... })  или func(arg)   если аргумент один
        return {arg1, ...}; или return arg; если аргумент один

    Объекты инициализируются так:
    
        1)  Скалярные типы - передаём один аргумент и инициализируем им.

        2)  Классы - вызывается конструктор с подходящими типами параметров, если его нет, то ошибка.
                     explicit конструкторы не учитываются при выборе конструктора.

        3)  Агрегаты - каждый элемент агрегата инициализируется с помощью copy initialization.           
*/

#include <iostream>
#include <string>
using std::cout, std::endl, std::string;
using std::string_literals;

struct Book
{
    std::string title;
    int pages;
    float price;
};

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



int main()
{
    int a = 5;                  // скаляр, будет инициализирован значением 5

    std::string b = "Alice";    // класс, вызовется конструктор string(const char* str)

    Book c = {"Harry Potter", 500, 1000.0}; 
                                // агрегат, для c.title вызовется конструктор string(const char* str),
                                // а c.pages и c.price будут иницализированы значениями 500 и 1000.0

    Verbose d[3] = {"Daniel"s, "Daisy"s, "David"s};
                                // агрегат, для всех элементов вызовутся конструкторы Verbose(const std::string& str)
}

