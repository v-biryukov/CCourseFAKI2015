/*
    Задача:

        Напишите конструктор перемещения и оператор присваивания перемещения для класса
        mipt::String из второго семинара.
*/

#include <iostream>
#include <cstdlib>
using std::cout, std::cin, std::endl, std::size_t;

namespace mipt{

class String 
{
private:

    size_t mSize;
    size_t mCapacity;
    char* mpData;

public:

    String(const char* str) 
    {
        cout << "Constructor from const char* (" << str << ")" << endl;
        size_t i = 0;
        while (str[i] != '\0')
            i++;
        mSize = i;
        mCapacity = i + 1;

        mpData = new char[mCapacity];

        for (size_t i = 0; str[i]; i++)
            mpData[i] = str[i];
        mpData[mSize] = '\0';
    }

    String()
    {
        cout << "Default Constructor ()" << endl;

        mSize = 0;
        mCapacity = 1;
        mpData = new char[mCapacity];
        mpData[mSize] = '\0';
    }

    String(const String& s)
    {
        cout << "Copy Constructor (" << s.mpData << ")" << endl;

        mSize = s.mSize;
        mCapacity = mSize + 1;

        mpData = new char[mCapacity];

        for (size_t i = 0; i < mSize; i++)
            mpData[i] = s.mpData[i];
        mpData[mSize] = '\0';
    }

    ~String()
    {
        cout << "Destructor (" << mpData << ")" << endl;
        delete [] mpData;
    }

    void reserve(size_t capacity)
    {
        if (capacity <= mCapacity)
            return;

        mCapacity = capacity;
        char* newData = new char[mCapacity];

        for (size_t i = 0; i < mSize; ++i)
            newData[i] = mpData[i];
        newData[mSize] = '\0';

        delete [] mpData;
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
        cout << "Copy Assignment (left = " << mpData << ", right = " << right.mpData << ")" << endl;

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
        cout << "Adding operator (left = " << mpData << ", right = " << b.mpData << ")" << endl;

        String result;
        result.resize(mSize + b.mSize);

        for (size_t i = 0; i < mSize; ++i)
            result.mpData[i] = mpData[i];

        for (size_t i = 0; i < b.mSize; ++i)
            result.mpData[mSize + i] = b.mpData[i];

        result.mpData[result.mSize] = '\0';

        return result;
    }

    String& operator+=(const String& right)
    {
        *this = *this + right;
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

    char& operator[](size_t i)
    {
        return mpData[i];
    }

    char& at(size_t i)
    {
        if (i >= mSize)
        {
            cout << "Error! Index is out of bounds." << endl;
            std::exit(1);
        }
        return mpData[i];
    }

    void clear()
    {
        delete [] mpData;

        mSize = 0;
        mCapacity = 1;
        mpData = new char[mCapacity];
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

}


int main() 
{
    mipt::String a = "Axolotl";
    mipt::String b = "Bear";

    mipt::String c = a;
    mipt::String d = a + b;
}
