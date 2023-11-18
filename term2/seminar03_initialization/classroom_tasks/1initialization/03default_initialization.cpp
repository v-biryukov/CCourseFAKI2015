/*
    Default initialization (инициализация по умолчанию).

    Выглядит вот так:

        type a;

    Объекты инициализируются так:
    
        1)  Скалярные типы - не инициализируются.

        2)  Классы - вызывается конструктор по умолчанию (написанный вами или сгенерированный автоматически).
            Если такого конструктора нет, то это ошибка компиляции.

        3)  Агрегаты - каждый элемент агрегата инициализируется через default initialization.
*/

#include <iostream>
#include <string>
using std::cout, std::endl;

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
    int a;              // скаляр, не будет инициализирован, в a будет лежать произвольное значение

    std::string b;      // класс, вызовется конструктор по умолчанию, b будет пустой строкой ""

    Book c;             // агрегат, для c.title вызовется конструктор по умолчанию,
                        //          а c.pages и c.price не будут иницализированы

    Verbose d[3];       // агрегат, для всех элементов вызовется конструктор по умолчанию


    cout << "a: " << a << endl;
    cout << "b: " <<  b << endl;
    cout << "c.title: " <<  c.title << endl;
    cout << "c.pages: " <<  c.pages << endl;
    cout << "c.price: " <<  c.price << endl;
}

