#pragma once
#include <iostream>
#include <cstdlib>


class String 
{
private:

    std::size_t mSize;
    std::size_t mCapacity;
    char* mpData;

public:

    String(const char* str);

    String();
    String(const String& s);

    String(std::size_t n, char a);
    ~String();

    void reserve(std::size_t capacity);
    void resize(std::size_t size);

    String& operator=(const String& right);
    String operator+(const String& b);
    String& operator+=(const String& right);

    bool operator==(const String& right) const;
    bool operator<(const String& right) const;
    bool operator<=(const String& right) const;
    bool operator!=(const String& right) const;
    bool operator>(const String& right) const;
    bool operator>=(const String& right) const;

    char& operator[](std::size_t i);
    char& at(std::size_t i);

    void clear();
    void addCharacter(char c);

    std::size_t getSize()        const;
    std::size_t getCapacity()    const;
    const char* cStr()      const;
};


std::ostream& operator<<(std::ostream& out, const String& s);
std::istream& operator>>(std::istream& in, String& s);
