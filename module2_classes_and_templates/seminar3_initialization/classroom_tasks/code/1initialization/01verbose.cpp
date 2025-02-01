/*
    В следующих примерах нам понадобиться видеть когда вызывается тот или иной особый метод класса.
    Чтобы это можно видеть какой метод вызывается я написал специальный класс Verbose.
    (Verbose переводится как Многословный)

    Особенность этого класса в том, что при вызове его особых методов на экран будет печататься сообщение,
    о том какой метод был вызван. Это может быть полезным для изучения того, когда такие методы вызываются.
    
    Данная версия класса Verbose печатает названия следующих особых методов:

        1)  Конструктор по умолчанию (Default Constructor)
        2)  Деструктор (Destructor)
        3)  Конструктор копирования (Copy Constructor)
        4)  Оператор присваивания копирования (Copy Assignment Operator)

    Также печатает сообщение при входе в конструктор, который принимает аргумент типа std::string.


    Задача:

        Что напечатает данная программа?
        Попытайтесь догадаться до этого без запуска программы.
*/


#include <iostream>

class Verbose
{
private:
    std::string mName {};

public:
    Verbose()   
    {
        std::cout << "Default Constructor (" << mName << ")" << std::endl;
    }

    ~Verbose()  
    {
        std::cout << "Destructor (" << mName << ")" << std::endl;
    }

    Verbose(const std::string& name) : mName(name)
    {
        std::cout << "Constructor from std::string (" << mName << ")" << std::endl;
    }

    Verbose(const Verbose& v) : mName(v.mName) 
    {
        std::cout << "Copy Constructor (" << mName << ")" << std::endl;
    }

    Verbose& operator=(const Verbose& v)
    {
        mName = v.mName;
        std::cout << "Copy Assignment Operator (" << mName << ")" << std::endl;
        return *this;
    }

    std::string getName() const 
    {
        return mName;
    }
};


void take(Verbose v)
{
    std::cout << "Inside 'take' function: " << v.getName() << std::endl;
}


int main()
{
    Verbose a(std::string("Alice"));
    Verbose b;
    Verbose c(a);

    take(a);
}