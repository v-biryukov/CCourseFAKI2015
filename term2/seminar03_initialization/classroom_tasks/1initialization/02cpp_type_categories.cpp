/*
    Типы языка C++ поделим на 3 категории:

        1)  Скалярные типы или просто скаляры (числа, указатели)

        2)  Агрегаты: 
            a)  массивы
            b)  классы или структуры без конструкторов (за исключением тех, что создаются автоматически) 
                и без приватных полей.
                                        
        3)  Классы или структуры с конструкторами и/или приватными полями.

    
    int, float, double, char, int*      - это скаляры
    Book, int[10], Verbose[5]           - это агрегаты
    std::string, Verbose                - это классы

    Смысл такого разделения в том, что инициализация для типов из разных категорий работает по разному.
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
}

