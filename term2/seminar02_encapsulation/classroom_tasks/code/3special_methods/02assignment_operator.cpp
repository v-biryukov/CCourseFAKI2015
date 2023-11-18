/*
    Особые методы. Оператор присваивания

    Проверим, что компилятор автоматически генерирует оператор присваивания.
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
};

void print(const Book& x)
{
    cout << x.title << " " << x.pages << " " << x.price << endl;
}

int main() 
{
    Book a;

    a.title = "War and Peace";
    a.pages = 1000;
    a.price = 1100;

    Book b;
    b = a;
    print(b);
}



/*
    Что напечатает данная программа?

    Разберём код из функции main подробно:

        1)  Вызывается автоматически сгенерированный конструктор по умолчанию в строке: 

                Book a;

            При этом перед вызовом этого конструктора вызовется и конструктор класса String для поля title.


        2)  Полям объекта a присваиваются некоторые значения:

                a.title = "War and Peace";
                a.pages = 1000;
                a.price = 1100;

            Интересно отметить, что строка  a.title = "War and Peace"  работает, несмотря на то, что слева от знака 
            присваивания стоит объект типа String, а справа от знака присваивания стоит объект типа  const char[14].
            Типы не совпадают, но это работает, так как у класса String есть конструктор от const char*.
            Таким образом, сначала вызовется этот конструктор и создастся временный объект типа String, а потом
            вызовется оператор присваивания между двумя объектами класса String. 
            После этого временный объект удалится и, соответственно, вызовется его деструктор.


        3)  Вызывается автоматически сгенерированный конструктор по умолчанию в строке:

                Book b;


        4)  Вызывается автоматически сгенерированный оператор присваивания в строке:

                b = a;

            Оператор присваивания у класса Book не написан, поэтому компилятор автоматически его сгенерирует.
            Автоматически сгенерированный оператор присваивания присваивает каждое поле в соответствующее поле нового объекта.
            Если у поля есть оператор присваивания (как например у класса String), то вызывается оператор присваивания этого поля.
            Если у поля нет оператор присваивания (как например у int или float), то поле просто копируется побайтово.


        5)  Печатаем книгу b на экран.
            

        6)  Выходим из функции main и вызываем деструкторы для объектов a и b.
*/