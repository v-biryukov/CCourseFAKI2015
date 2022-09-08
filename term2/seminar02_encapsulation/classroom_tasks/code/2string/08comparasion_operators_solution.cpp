#include <iostream>
#include <iomanip>
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


    bool operator==(const String& right) const
    {
        if (mSize != right.mSize)
            return false;

        size_t i = 0;
        while (i < mSize && mpData[i] == right.mpData[i])
            i++;

        return i == mSize;
    }

    bool operator<(const String& right) const
    {
        size_t i = 0;
        while (i < mSize && i < right.mSize && mpData[i] == right.mpData[i])
            i++;

        return mpData[i] < right.mpData[i];
    }

    bool operator<=(const String& right) const
    {
        size_t i = 0;
        while (i < mSize && i < right.mSize && mpData[i] == right.mpData[i])
            i++;

        return mpData[i] <= right.mpData[i];
    }

    bool operator!=(const String& right) const
    {
        return !(*this == right);
    }

    bool operator>(const String& right) const
    {
        return !(*this <= right);
    }

    bool operator>=(const String& right) const
    {
        return !(*this < right);
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
    cout << std::boolalpha;

    String a = "Cat";
    String b = "Camel";

    cout << (a > b) << endl;
    cout << (a < b) << endl;
    cout << (a == b) << endl;
    cout << (a == a) << endl;


    String c = "Catharsis";

    cout << (a > c) << endl;
    cout << (a < c) << endl;
    cout << (a == c) << endl;
    cout << (a != c) << endl;
}