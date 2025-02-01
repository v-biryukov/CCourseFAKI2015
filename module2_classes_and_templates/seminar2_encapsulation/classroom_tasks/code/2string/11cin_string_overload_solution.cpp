#include <iostream>
#include <iomanip>
#include <cstdlib>
using std::cout, std::cin, std::endl, std::size_t;


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

    char& operator[](size_t i)
    {
        return mpData[i];
    }

    void clear()
    {
        std::free(mpData);

        mSize = 0;
        mCapacity = 1;
        mpData = (char*)std::malloc(sizeof(char) * mCapacity);
        mpData[0] = '\0';
    }

    void addCharacter(char c)
    {
        if (mSize + 1 == mCapacity)
            reserve(2 * mCapacity);

        mpData[mSize] = c;
        resize(mSize + 1);
    }


    size_t getSize()        const   {return mSize;}
    size_t getCapacity()    const   {return mCapacity;}
    const char* cStr()      const   {return mpData;}
};


std::ostream& operator<<(std::ostream& out, const String& s) 
{
    out << s.cStr();
    return out;
}


std::istream& operator>>(std::istream& in, String& s) 
{
    s.clear();
    while (true)
    {
        char x = in.get();
        if (x == ' ' || x == '\n' || x == '\t')
            break;
        s.addCharacter(x);
    }
    return in;
}


int main() 
{
    String a, b;
    cin >> a >> b;
    cout << a + b << endl;

    a.addCharacter('!');
    cout << a << endl;
}