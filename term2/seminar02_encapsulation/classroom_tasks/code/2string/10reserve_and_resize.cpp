#include <iostream>
#include <iomanip>
#include <cstdlib>
using std::cout, std::endl;


/*
    Напишем ещё 2 очень полезных метода:

        1)  reserve  -  увеличивает вместимость строки, на вход методу передаётся новая вместмость
                        если новая вместимость меньше старой, то ничего не происходит (вместимость не уменьшается)
                        размер и содержимое строки не меняется


        2)  resize   -  изменяет размер строки, на вход методу передаётся новый размер
                        если новый размер меньше старого, то строка усекается
                        при необходимости увеличивает вместимость

    Используя эти два метода можно немного упростить код для операторов сложения и присваивания.
    Эти методы могут быть полезны и для программиста, который будет работать с нашей строкой, поэтому сделаем их публичными.
*/


class String 
{
private:

    size_t mSize;
    size_t mCapacity;
    char* mpData;

public:

    String(const char* str) 
    {
        int i = 0;
        while (str[i] != '\0')
            i++;
        mSize = i;
        mCapacity = i + 1;

        mpData = (char*)std::malloc(sizeof(char) * mCapacity);

        for (int i = 0; str[i]; i++)
            mpData[i] = str[i];
        mpData[mSize] = '\0';
    }

    String() : String("") {}
    String(const String& s) : String(s.cStr()) {}


    ~String()
    {
        std::free(mpData);
    }


    void reserve(size_t capacity)
    {
        if (capacity <= mCapacity)
            return;

        mCapacity = capacity;
        char* newData = (char*)std::malloc(sizeof(char) * mCapacity);

        for (size_t i = 0; i < mSize; ++i)
            newData[i] = mpData[i];
        newData[mSize] = '\0';

        std::free(mpData);
        mpData = newData;
    }


    void resize(size_t size)
    {
        reserve(size + 1);
        mSize = size;
        mpData[mSize] = '\0';
    }


    String& operator=(const String& right)
    {
        if (this == &right)
            return *this;

        mSize = right.mSize;
        resize(mSize);

        for (size_t i = 0; i <= mSize; ++i)
            mpData[i] = right.mpData[i];

        return *this;
    }


    String operator+(const String& b)
    {
        String result;
        result.resize(mSize + b.mSize);

        for (size_t i = 0; i < mSize; ++i)
            result.mpData[i] = mpData[i];

        for (size_t i = 0; i < b.mSize; ++i)
            result.mpData[mSize + i] = b.mpData[i];

        result.mpData[result.mSize] = '\0';

        return result;
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
    String b = "Dog";

    cout << a.getCapacity() << endl;
    a.reserve(10);
    cout << a.getCapacity() << endl;

    cout << a + b << endl;


    String c = "Sapere Aude";
    cout << c << endl;

    c.resize(6);
    cout << c << endl;
}
