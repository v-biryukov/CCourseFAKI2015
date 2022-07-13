#pragma once
#include <iostream>
#include <cstdlib>

namespace mipt {

class String 
{
private:

    size_t mSize;
    size_t mCapacity;
    char* mpData;

public:

    String(const char* str);

    String();
    String(const String& s);

    String(size_t n, char a);
    ~String();

    void reserve(size_t capacity);
    void resize(size_t size);

    String& operator=(const String& right);
    String operator+(const String& b);
    String& operator+=(const String& right);

    bool operator==(const String& right) const;
    bool operator<(const String& right) const;
    bool operator<=(const String& right) const;
    bool operator!=(const String& right) const;
    bool operator>(const String& right) const;
    bool operator>=(const String& right) const;

    char& operator[](size_t i);
    char& at(size_t i);

    void clear();
    void addCharacter(char c);

    size_t getSize()        const;
    size_t getCapacity()    const;
    const char* cStr()      const;
};


std::ostream& operator<<(std::ostream& out, const String& s);
std::istream& operator>>(std::istream& in, String& s);

}