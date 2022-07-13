#include <iostream>
#include <cstdlib>
using std::cout, std::endl;


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

    String() : String("") 
    {
        cout << "String Default Constructor" << endl;
    }
    String(const String& s) : String(s.cStr()) 
    {
        cout << "String Copy Constructor" << endl;
    }

    ~String()
    {
        cout << "String Destructor" << endl;
        std::free(mpData);
    }

    String& operator=(const String& right)
    {
        cout << "String Assgnment Operator" << endl;
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
private:
    String  mName;
    int     mPages;
    float   mPrice;

public:

    Book(String name, int pages, float price)
    {
        mName = name;
        mPages = pages;
        mPrice = price;
    }
};


int main() 
{
    Book b("War and Peace", 1000, 800);
}

