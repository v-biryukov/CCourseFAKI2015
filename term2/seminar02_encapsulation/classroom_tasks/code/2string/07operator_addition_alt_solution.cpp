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
        if (mCapacity < mSize + right.mSize + 1)
        {
            mCapacity = mSize + right.mSize + 1;
            char* pNewData = (char*)std::malloc(sizeof(char) * mCapacity);

            for (size_t i = 0; i < mSize; ++i)
                pNewData[i] = mpData[i];

            std::free(mpData);
            mpData = pNewData;
        }

        for (size_t i = 0; i < right.mSize; ++i)
            mpData[mSize + i] = right.mpData[i];

        mSize += right.mSize;
        mpData[mSize] = '\0';

        return *this;
    }

    String operator+(const String& b)
    {
        String result = *this;
        result += b;
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
    String a = "Mouse";
    String b = "Elephant";

    cout << a + b << endl;
}