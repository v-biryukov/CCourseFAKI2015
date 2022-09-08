#include <iostream>
#include <cstdlib>
#include "string.hpp"

namespace mipt {

String::String(const char* str) 
{
    std::size_t i = 0;
    while (str[i] != '\0')
        i++;
    mSize = i;
    mCapacity = i + 1;

    mpData = (char*)std::malloc(sizeof(char) * mCapacity);

    for (std::size_t i = 0; str[i]; i++)
        mpData[i] = str[i];
    mpData[mSize] = '\0';
}

String::String() : String("") {}
String::String(const String& s) : String(s.cStr()) {}

String::String(std::size_t n, char a)
{
    mSize = n;
    mCapacity = n + 1;
    mpData = (char*)std::malloc(sizeof(char) * mCapacity);

    for (std::size_t i = 0; i < mSize; ++i)
        mpData[i] = a;
    mpData[mSize] = '\0';
}

String::~String()
{
    std::free(mpData);
}

void String::reserve(std::size_t capacity)
{
    if (capacity <= mCapacity)
        return;

    mCapacity = capacity;
    char* newData = (char*)std::malloc(sizeof(char) * mCapacity);

    for (std::size_t i = 0; i < mSize; ++i)
        newData[i] = mpData[i];
    newData[mSize] = '\0';

    std::free(mpData);
    mpData = newData;
}


void String::resize(std::size_t size)
{
    reserve(size + 1);
    mSize = size;
    mpData[mSize] = '\0';
}


String& String::operator=(const String& right)
{
    if (this == &right)
        return *this;

    mSize = right.mSize;
    resize(mSize);

    for (std::size_t i = 0; i <= mSize; ++i)
        mpData[i] = right.mpData[i];

    return *this;
}


String String::operator+(const String& b)
{
    String result;
    result.resize(mSize + b.mSize);

    for (std::size_t i = 0; i < mSize; ++i)
        result.mpData[i] = mpData[i];

    for (std::size_t i = 0; i < b.mSize; ++i)
        result.mpData[mSize + i] = b.mpData[i];

    result.mpData[result.mSize] = '\0';

    return result;
}

String& String::operator+=(const String& right)
{
    *this = *this + right;
    return *this;
}

bool String::operator==(const String& right) const
{
    if (mSize != right.mSize)
        return false;

    std::size_t i = 0;
    while (i < mSize && mpData[i] == right.mpData[i])
        i++;

    return i == mSize;
}

bool String::operator<(const String& right) const
{
    std::size_t i = 0;
    while (i < mSize && i < right.mSize && mpData[i] == right.mpData[i])
        i++;

    return mpData[i] < right.mpData[i];
}

bool String::operator<=(const String& right) const
{
    std::size_t i = 0;
    while (i < mSize && i < right.mSize && mpData[i] == right.mpData[i])
        i++;

    return mpData[i] <= right.mpData[i];
}

bool String::operator!=(const String& right) const
{
    return !(*this == right);
}

bool String::operator>(const String& right) const
{
    return !(*this <= right);
}

bool String::operator>=(const String& right) const
{
    return !(*this < right);
}

char& String::operator[](std::size_t i)
{
    return mpData[i];
}

char& String::at(std::size_t i)
{
    if (i >= mSize)
    {
        std::cout << "Error! Index is out of bounds." << std::endl;
        std::exit(1);
    }
    return mpData[i];
}

void String::clear()
{
    std::free(mpData);

    mSize = 0;
    mCapacity = 1;
    mpData = (char*)std::malloc(sizeof(char) * mCapacity);
    mpData[0] = '\0';
}

void String::addCharacter(char c)
{
    if (mSize + 1 == mCapacity)
        reserve(2 * mCapacity);

    mpData[mSize] = c;
    resize(mSize + 1);
}


std::size_t String::getSize()        const   {return mSize;}
std::size_t String::getCapacity()    const   {return mCapacity;}
const char* String::cStr()      const   {return mpData;}


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

}