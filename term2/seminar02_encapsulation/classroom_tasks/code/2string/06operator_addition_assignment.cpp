/*
    Оператор присваивания сложения +=

    Очень похож на оператор присваивания, разница только в том, каким станет левый операнд после применения этого оператора
    К левому операнду в этом случае должна прибавиться копия правого оператора

    Если   a = "Cat"  ,   b = "Dog"   , то после применения   a += b   строка a будет равна "CatDog"



    Прототип оператора присваивания сложения как метода класса String должен выглядеть так:

        String& operator+=(const String& b)
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
        size_t i = 0;
        while (str[i] != '\0')
            i++;
        mSize = i;
        mCapacity = i + 1;

        mpData = (char*)std::malloc(sizeof(char) * mCapacity);

        for (size_t i = 0; str[i]; i++)
            mpData[i] = str[i];
        mpData[mSize] = '\0';
    }

    String() : String("") {}
    String(const String& s) : String(s.cStr()) {}


    ~String()
    {
        std::free(mpData);
    }

    String operator+(const String& b)
    {
        String result;

        result.mSize = mSize + b.mSize;
        result.mCapacity = result.mSize + 1;
        result.mpData = (char*)std::malloc(sizeof(char) * result.mCapacity);

        for (size_t i = 0; i < mSize; ++i)
            result.mpData[i] = mpData[i];

        for (size_t i = 0; i < b.mSize; ++i)
            result.mpData[mSize + i] = b.mpData[i];

        result.mpData[result.mSize] = '\0';

        return result;
    }


    String& operator=(const String& right)
    {
        if (this == &right)
            return *this;


        mSize = right.mSize;
        mCapacity = right.mCapacity;

        std::free(mpData);
        mpData = (char*)malloc(sizeof(char) * mCapacity);

        for (size_t i = 0; i <= mSize; ++i)
            mpData[i] = right.mpData[i];

        return *this;
    }



    String& operator+=(const String& right)
    {
        // Ваш код нужно написать здесь
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
    String a = "Mouse";
    String b = "Elephant";

    b += a;

    cout << b << endl;
}



/* 
    Задание:

        1)  Написать оператор присваивания сложения для строки String в виде метода класса String

            Подсказка: можно использовать уже написанные операторы, чтобы реализовать этот
*/
