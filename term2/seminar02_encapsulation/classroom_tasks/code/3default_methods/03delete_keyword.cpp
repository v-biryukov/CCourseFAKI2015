/*
    Удалённые методы
*/

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
        cout << "String Constructor from const char*  (" << str << ")" << endl;

        size_t i = 0;
        while (str[i] != '\0')
            i++;
        mSize = i;
        mCapacity = i + 1;

        mpData = (char*)std::malloc(sizeof(char) * mCapacity);

        for (size_t i = 0; str[i]; ++i)
            mpData[i] = str[i];
        mpData[mSize] = '\0';
    }

    String()
    {
        cout << "String Default Constructor" << endl;
        mSize = 0;
        mCapacity = 1;
        mpData = (char*)std::malloc(sizeof(char));
        mpData[0] = '\0';
    }

    String(const String& s) 
    {
        cout << "String Copy Constructor  (" << s.mpData << ")" << endl;

        size_t i = 0;
        mSize = s.mSize;
        mCapacity = mSize + 1;

        mpData = (char*)std::malloc(sizeof(char) * mCapacity);

        for (size_t i = 0; i < mSize; ++i)
            mpData[i] = s.mpData[i];
        mpData[mSize] = '\0';
    }

    ~String()
    {
        cout << "String Destructor  (" << mpData << ")" << endl;
        std::free(mpData);
    }

    String& operator=(const String& right)
    {
        cout << "String Assignment Operator  (" << right.mpData << ")" << endl;
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

    char& operator[](size_t i)
    {
        return mpData[i];
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



class Book
{
public:
    String title;
    int pages;
    float price;

    Book() {};

    Book(const String& aTitle, int aPages, float aPrice)
    {
        title = aTitle;
        pages = aPages;
        price = aPrice;
    }

    Book(const Book& b) = delete;
};


int main() 
{
    Book a;

    Book b = a;
}



/*
    Если же вы не хотите создавать какой-либо метод и не хотите чтобы он создавался автоматически, 
    то его можно удалить с помощью ключевого слова delete.

    
    Например, в этом примере у класса Book удалён конструктор копирования вот так:

        Book(const Book& b) = delete;

    Это означает, что конструктор копирования не создастся автоматически.
    Поэтому в строке:

        Book b = a;

    произойдёт ошибка компиляции.



    Задача:

        1)  Можно ли передать объект класса с удалённым конструктором копирования в функцию по значению?
            
            Например, если есть функция:

                void print(Book b)
                {
                    cout << b.title << " "<< b.pages << " " << b.price << endl;
                }

            Можно ли туда передать что-нибудь?

*/