#include <iostream>
#include <string>
using std::cout, std::endl;

class Book
{
private:

    std::string mTitle;
    int mPages;
    float mPrice;

public:

    Book(const std::string& title, int pages, float price) : mTitle(title), mPages(pages), mPrice(price)
    {
        mTitle = title;
    }


    Book(int x) : mTitle(std::to_string(x)), mPages(x), mPrice(x)
    {
    }


    Book(const Book& b) : mTitle{b.mTitle}, mPages{b.mPages}, mPrice{b.mPrice}
    {
    }
    

    Book() : mTitle(), mPages(), mPrice()
    {
    }


    void print()
    {
        cout << mTitle << ", pages = " << mPages << ", price = " << mPrice << endl;
    }
};


int main()
{
    Book a("Harry Potter", 1000, 2000);
    a.print();


    Book b(123);
    b.print();


    Book c(a);
    c.print();


    Book d;
    d.print();
}