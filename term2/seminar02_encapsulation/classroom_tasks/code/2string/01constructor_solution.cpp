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
        cout << "Construtor from const char*" << endl;
        size_t i = 0;
        while (str[i] != '\0')
            i++;
        mSize = i;
        mCapacity = i + 1;

        mpData = (char*)std::malloc(sizeof(char) * mCapacity);

        for (size_t i = 0; str[i] != '\0'; i++)
            mpData[i] = str[i];
        mpData[mSize] = '\0';
    }

    String()
    {
        cout << "Default Construtor" << endl;
        mSize = 0;
        mCapacity = 1;
        mpData = (char*)std::malloc(sizeof(char) * mCapacity);
        mpData[0] = '\0';
    }

    String(size_t n, char a)
    {
        cout << "Construtor n equal characters" << endl;
        mSize = n;
        mCapacity = n + 1;
        mpData = (char*)std::malloc(sizeof(char) * mCapacity);

        for (size_t i = 0; i < mSize; ++i)
            mpData[i] = a;
        mpData[mSize] = '\0';
    }


    String(const String& s)
    {
        cout << "Copy Constructor" << endl;
        mSize = s.mSize;
        mCapacity = s.mCapacity;
        mpData = (char*)std::malloc(sizeof(char) * mCapacity);

        for (size_t i = 0; i < mSize; ++i)
            mpData[i] = s.mpData[i];
        mpData[mSize] = '\0';
    }

    size_t getSize() const 
    {
        return mSize;
    }

    size_t getCapacity() const 
    {
        return mCapacity;
    }

    const char* cStr() const 
    {
        return mpData;
    }
};


std::ostream& operator<<(std::ostream& left, const String& right) 
{
    left << right.cStr();
    return left;
}


int main() 
{
    String a;
    cout << a << endl << endl;

    String b(10, 'q');
    cout << b << endl << endl;
    

    String c = "Cat";
    cout << c << endl << endl;


    String d(c);
    cout << c << endl << endl;
}
