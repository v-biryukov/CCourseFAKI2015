/*
    Список инициализации членов класса

    Данный пример демонстрирует разницу между конструктором, в котором не используется список инициализации, 
    и конструктором, в котором список инициализации используется.

    Написано два похожих класса Cat и Dog. 

    В классе Cat поле mName сначала инициализируется по умолчанию, а потом задаётся в конструкторе нужным
    значением с помощью оператора присваивания. Поэтому сначала вызовется конструктор по умолчанию класса
    Verbose, а потом оператор присваивания класса Verbose.

    В классе Dog поле mName сразу инициализируется нужным значением с помощью direct-инициализации.
    Поэтому в этом случае просто вызовется необходимый конструктор.


    Задача:

        Что напечатает данная программа? Попробуйте догадаться без запуска программы.
        Запустите программу и проверьте свою догадку.
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


class Cat
{
private:

    Verbose mName;

public:

    Cat(const Verbose& name)
    {
        mName = name;
    }
};



class Dog
{
private:

    Verbose mName;

public:

    Dog(const Verbose& name) : mName{name}
    {
    }
};



int main()
{
    Verbose name("Alice");


    cout << endl << "Creating object of Cat" << endl;
    Cat a(name);


    cout << endl << "Creating object of Dog" << endl;
    Dog b(name);


    cout << endl;
}