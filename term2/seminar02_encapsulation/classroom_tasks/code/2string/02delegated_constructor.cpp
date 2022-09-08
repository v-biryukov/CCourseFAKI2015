/*
    Делегирующий конструктор

    В разных конструкторах может быть повторяющийся код.
    Повторений кода иногда можно избежать если писать один конструктор на основе уже написанного.

    Это можно сделать с помощью синтаксиса так называемого делегирующего конструктора
    После объявления конструктора, но перед его телом можно написать двоеточие и вызвать другой конструктор
    
    Например:

        String() : String("")
        {
            cout << "Default Constructor" << endl;
        }

    Этот конструктор сначала вызовет конструктор String(const char* str) с аргументом "" (то есть пустой строкой)
    а потом исполнит тело данного коструктора (в данном случае напечатает Default Constructor).
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
        cout << "Constructor" << endl;
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

    String() : String("")
    {
        cout << "Default Constructor" << endl;
    }


    String(const String& s) : String(s.cStr())
    {
        cout << "Copy Constructor" << endl;
    }

    size_t getSize() const 
    {
        return mSize;
    }

    size_t getCapacity() const 
    {
        return mCapacity;
    }

    const char* cStr() const 
    {
        return mpData;
    }
};


std::ostream& operator<<(std::ostream& left, const String& right) 
{
    left << right.cStr();
    return left;
}


int main() 
{
    String a;
    cout << "a = " << a << endl << endl;


    String b = "Cat";
    cout << "b = " << b << endl << endl;


    String c(b);
    cout << "c = " << c << endl << endl;
}





/*
    Задача:

        Попробуйте понять без запуска, что напечатает данная программа
*/