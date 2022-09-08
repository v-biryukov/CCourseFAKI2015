/*
    Оператор сложения

    Оператор сложения для строк должен принимать 2 строки и возвращать новую строку, равную результату конкатенации двух строк
    Если строка  a = "Cat"  , а строка  b = "Mouse"  , то их конкатенация это  a + b = "CatMouse"

    Оператор сложения должен принимать свои аргументы по константной ссылке
        по ссылке, чтобы не копировать объект лишний раз при передаче в функцию
        по константной, потому что мы не будем менять принимаемые объекты внутри функции


    То есть прототип оператора сложения, если его делать с помощью обычной функции, должен выглядеть так:

        String operator+(const String& a, const String& b)


    Прототип оператора сложения, если его делать с помощью метода класса String, должен выглядеть так:

        String operator+(const String& b) const
*/

#include <iostream>
#include <cstdlib>
using std::cout, std::endl, std::size_t;

class String 
{
private:

    size_t mSize;
    size_t mCapacity;
    char* mpData;

public:

    String(const char* str) 
    {
        cout << "Constructor of " << str << endl;
        size_t i = 0;
        while (str[i] != '\0')
            i++;
        mSize = i;
        mCapacity = i + 1;

        mpData = (char*)std::malloc(sizeof(char) * mCapacity);

        for (size_t i = 0; str[i] != '\0'; i++)
            mpData[i] = str[i];
        mpData[mSize] = '\0';
    }

    String() : String("") {}
    String(const String& s) : String(s.cStr()) {}


    ~String()
    {
        cout << "Destructor of " << mpData << endl;
        std::free(mpData);
    }


    size_t getSize()        const   {return mSize;}
    size_t getCapacity()    const   {return mCapacity;}
    const char* cStr()      const   {return mpData;}
};


std::ostream& operator<<(std::ostream& left, const String& right) 
{
    left << right.cStr();
    return left;
}


int main() 
{
    String a = "Cat";
    String b = "Mouse";
      
    cout << a + b << endl;
}



/* 
    Задание:
    
        1)  Написать оператор сложения для строки String в виде свободной функции
            В этом случае эту функцию нужно сделать дружественной классу String,
            чтобы она имела доступ к приватным полям класса

        2)  Написать оператор сложения для строки String в виде метода класса String
*/
