#pragma once
#include <iostream>


class Book 
{
private:
    std::string mTitle  {};
    int         mNumPages  {};
    float       mPrice  {};

public:
    Book(std::string title, int numPages, float price) : mTitle{title}, mNumPages{numPages}, mPrice{price} {}

    float getPrice() const {return mPrice;}
    void setPrice(float newPrice) { mPrice = newPrice;}
    friend std::ostream& operator<<(std::ostream& out, const Book& b);
};

std::ostream& operator<<(std::ostream& out, const Book& b)
{
    out << b.mTitle << ", number of pages = " << b.mNumPages << ", price = " << b.mNumPages;
    return out;
}