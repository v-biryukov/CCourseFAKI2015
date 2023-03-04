/*
    Полная специализация







*/

#include <cstddef>
#include <iostream>
#include <string>



template <typename T>
size_t totalSize(const T& a)
{
    return sizeof(a);
}

template <>
size_t totalSize(const std::string& a)
{
    return sizeof(a) + sizeof(char) * a.capacity();
}



int main()
{
    int a = 123;
    double b = 1.5;
    std::string c {""};


}