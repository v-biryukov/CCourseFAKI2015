/*
    Ключевое слово explicit.
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

    explicit String(const char* s) 
    {
        cout << "String Constructor from const char*  (" << s << ")" << endl;

        size_t i = 0;
        while (s[i] != '\0')
            i++;
        mSize = i;
        mCapacity = i + 1;

        mpData = (char*)std::malloc(sizeof(char) * mCapacity);

        for (size_t i = 0; s[i]; ++i)
            mpData[i] = s[i];
        mpData[mSize] = '\0';
    }

    explicit String(int n)
    {
        cout << "String Constructor from int  (" << n << ")" << endl;

        mSize = n;
        mCapacity = mSize + 1;
        mpData = (char*)std::malloc(sizeof(char) * mCapacity);
        for (size_t i = 0; i < mSize; ++i)
            mpData[i] = 'a';
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



void print(String s)
{
    cout << s << endl;
}


int main() 
{
    String a;
    a = "Dog";

    print("Mouse");
    print(10);
}



/*
    Иногда всё-таки не хочется, чтобы конструкторы использовались для неявного приведения типов.
    Ведь такое приведение типов может произойти там, где мы этого не хотим.

    Чтобы конструктор не использовался для неявного приведения, его нужно пометить с помощью ключевого слова explicit.
    В этом примере, конструкторы   String(const char* s)  и  String(int n)  помечены как explicit.
    Поэтому эти конструкторы не будут использоваться для неявного приведения типов и код в функции main выдаст ошибку.
    Но эти конструкторы всё равно можно вызывать явно, вот так:

        String a;
        a = String("Dog");

        print(String("Mouse"));
        print(String(10));
*/