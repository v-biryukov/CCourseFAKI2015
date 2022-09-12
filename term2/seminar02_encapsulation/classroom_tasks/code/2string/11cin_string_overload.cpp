/*
    Считывание строки с экрана

    Помимо удобной печати на экран с помощью объекта std::cout, хотелось бы добавить удобное считываие строки
    с помощью объекта std::cin.

    Для этого нужно перегрузить оператор >> с объектами типа  std::istream  и  String, то есть написать функцию:

        std::istream& operator>>(std::istream& in, String& str)

    Эта функция должна считывать символы из стандартного входа и добавлять в строку
    Основная проблема в том, что мы не знаем сколько символов нужно считать, поэтому нужно считывать
    посимвольно и добавлять символы по одному в строку пока не встретим пробельный символ (' ' или '\n' или '\t')

    Для упрощения программы можно написать дополнительные методы

        void clear()               -  метод, который будет очищать строку
                                      mSize = 0, mCapacity = 1, строка по адресу mpData равна "\0"
    
        void addCharacter(char c)  -  добавляет символ в конец строки
                                      если у строки не хватает вместимости, то удваивает вместимость.


    Для того, чтобы считать символ из стандартного входа можно использовать метод get класса istream
    Этот метод возвращает следующий символ из стандартного входа

        char x = cin.get();


    Задачи:

        1)  Напишите метод clear.

        2)  Напишите метод addCharacter.

        3)  Напишите перегруженный оператор >> для считывания строки с экрана.
            std::istream& operator>>(std::istream& in, String& s) 
*/

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


    size_t getSize()        const   {return mSize;}
    size_t getCapacity()    const   {return mCapacity;}
    const char* cStr()      const   {return mpData;}
};


std::ostream& operator<<(std::ostream& left, const String& right) 
{
    left << right.cStr();
    return left;
}


int main() 
{
    String a, b;
    cin >> a >> b;
    cout << a + b;

    a.addCharacter('!');
    cout << a << endl;
}