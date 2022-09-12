/*
    Замечание по поводу автоматической генерации конструктора по умолчанию
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
        cout << "String Constructor from const char*  (" << str << ")" << endl;

        size_t i = 0;
        while (str[i] != '\0')
            i++;
        mSize = i;
        mCapacity = i + 1;

        mpData = (char*)std::malloc(sizeof(char) * mCapacity);

        for (size_t i = 0; str[i]; ++i)
            mpData[i] = str[i];
        mpData[mSize] = '\0';
    }

    String()
    {
        cout << "String Default Constructor" << endl;
        mSize = 0;
        mCapacity = 1;
        mpData = (char*)std::malloc(sizeof(char));
        mpData[0] = '\0';
    }

    String(const String& s) 
    {
        cout << "String Copy Constructor  (" << s.mpData << ")" << endl;

        size_t i = 0;
        mSize = s.mSize;
        mCapacity = mSize + 1;

        mpData = (char*)std::malloc(sizeof(char) * mCapacity);

        for (size_t i = 0; i < mSize; ++i)
            mpData[i] = s.mpData[i];
        mpData[mSize] = '\0';
    }

    ~String()
    {
        cout << "String Destructor  (" << mpData << ")" << endl;
        std::free(mpData);
    }

    String& operator=(const String& right)
    {
        cout << "String Assignment Operator  (" << right.mpData << ")" << endl;
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

    char& operator[](size_t i)
    {
        return mpData[i];
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



class Book
{
public:
    String title;
    int pages;
    float price;

    Book(const String& aTitle, int aPages, float aPrice)
    {
        title = aTitle;
        pages = aPages;
        price = aPrice;
    }
};


int main() 
{
    Book a;
}



/*
    Конструктор по умолчанию не генерируется автоматически если у класса написан хотя бы один конструктор (любой).
    Например, в этом пример у класса Book написан один конструктор:

        Book(const String& aTitle, int aPages, float aPrice)

    Поэтому в данном случае конструктор по умочанию автоматически генерироваться не будет.

    
    В строке  Book a;  должен быть вызван конструктор по умолчанию.
    Но у класса Book такого конструктора нет и автоматически он не был создан. Поэтому эта строка приведёт к ошибке.


    Но конструктор копирования, оператор присваивания и деструктор автоматически генерироваться будут.


    Задача:

        Исправьте ошибку, написав конструктор по умолчанию самостоятельно.
*/