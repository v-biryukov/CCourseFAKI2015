/*
    Класс Verbose (Verbose переводится как Многословный).

    
    Полезный класс, который печатает названия особых методов, при входе в них.
    Это может быть полезным для изучения того, когда такие методы вызываются.
    

    Данная версия печатает названия следующих особых методов:

        1)  Конструктор по умолчанию (Default Constructor)
        2)  Деструктор (Destructor)
        3)  Конструктор копирования (Copy Constructor)
        4)  Оператор присваивания копирования (Copy Assignment Operator)

    Также печатает сообщение при входе в конструктор, который принимает аргумент типа std::string.


    Для печати особых методов, связанных с move-семантикой смотрите вторую версию
    данного класса в файле verbose_v2.cpp.
*/



#include <iostream>
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

    std::string getName() const {return mName;}
};



Verbose get()
{
    Verbose result(std::string("Casper"));
    return result;
}


void take(Verbose v)
{
    std::cout << "Inside 'take' function: " << v.getName() << std::endl;
}


int main()
{
    Verbose a = std::string("Alice");
    Verbose c = get();

    take(a);
}