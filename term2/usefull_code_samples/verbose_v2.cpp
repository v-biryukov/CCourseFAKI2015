/*
    Класс Verbose (Verbose переводится как Многословный). Версия 2.

    
    Полезный класс, который печатает названия особых методов, при входе в них.
    Это может быть полезным для изучения того, когда такие методы вызываются.
    

    Данная версия печатает названия следующих особых методов:

        1)  Конструктор по умолчанию (Default Constructor)
        2)  Деструктор (Destructor)
        3)  Конструктор копирования (Copy Constructor)
        4)  Оператор присваивания копирования (Copy Assignment Operator)
        5)  Конструктор перемещения (Move Constructor)
        6)  Оператор присваивания перемещения (Move Assignment Operator)

    Также печатает сообщение при входе в конструкторы, которые принимают аргумент
    типа std::string и const char*.
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



Verbose get1()
{
    Verbose result{"Alice"};
    return result;
}

Verbose get2()
{
    Verbose result{"Alice"};
    return std::move(result);
}


void take(Verbose v)
{
    std::cout << "Inside 'take' function: " << v.getName() << std::endl;
}


int main()
{
    Verbose a = get1();

    Verbose b;
    b = std::move(a);

    take(std::move(b));
}


/*

    Задача на RVO:

        Какая из функций лучше get1 или get2?

*/