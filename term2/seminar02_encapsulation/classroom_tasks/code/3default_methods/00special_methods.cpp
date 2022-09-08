/*
    Особые методы

    В прошлой части мы рассмотрели различные методы классов. Некоторые из этих методов называются особыми.
    Они выделяются по сравнению с другими методами тем, что они будут создаваться автоматически даже если вы их не напишите.
    К особым методам класса относятся:


        1)  Конструктор по умолчанию. То есть конструктор, который не принимает ни одного аргумента.
            В случае со строкой String это контруктор:

                String()


        2)  Конструктор копирования. То есть конструктор, который создаёт объект из другого объекта такого же типа, что и данный.
            В случае со строкой String это контруктор:

                String(const String& s) 


        3)  Деструктор. Это метод, который вызывается при удалении объекта. В отличии от конструкторов, деструктор у объекта всегда один.
            В случае со строкой String это:

                ~String()

        
        4)  Оператор присваивания. Это метод, который вызывается при присваивании одного метода класса String другому методу класса String.
            В случае со строкой String это:

                String& operator=(const String& right)



        5,6)    Есть ещё 2 особых метода, которые мы пройдём позже.
    

    Все остальные методы, включаю другие конструкторы и перегруженные операторы, к особым методам не относятся.
    То есть остальные методы не могут создаваться автоматически.


    В этой части мы рассмотрим при каких условиях происходит вызов того или иного особого метода.
    Для этого будем использовать класс String, в котором была добавлена печать на экран для каждого особого метода и для коструктора из const char*.
    Например, конструктор по умолчанию будет печатать Default Constructor и т. д.
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


int main() 
{
    Book a = Book();
    cout << a.title << " " << a.pages << " " << a.price << endl;
}



/*
    У класса Book есть 3 поля, одно из которых имеет тип String.
    Но у класса Book не определён ни один метод. У него нет никаких конструкторов или перегруженных операторов.

    Теперь посмотрим на код:

        Book a = Book();

    Тут мы создаём объект типа Book с помощью конструктора по умолчанию. Но у Book не написан конструктор по умолчанию!
    Что же произойдёт в этом случае? Ошибка? Нет, на самом деле в этом случае конструктор будет создан автоматически. Вот такой:

        Book() {}

    Автоматически-сгенерированный конструктор по умолчанию ничего не делает.
    Тем не менее, перед вызовом этого конструктора, компилятор должен вызвать конструктор по умолчанию для всех полей класса, 
    у которых есть конструктор по умолчанию.
    В этом случае, при создании объекта класса Book с помощью конструктора по умолчанию, будет вызван конструктор по умолчанию класса String.


    
    Аналогично, автоматически сгенерируется деструктор по умолчанию, вот такой:

        ~Book() {}

    Он пустой, но нужно помнить, что после вызова деструктора класса, автоматически вызываются деструкторы для все его полей (у которых есть деструкторы)
    В этом случае, после вызова деструктора класса Book вызовется деструктор класса String.





    Задачи:

        1)  Скомпилируйте программу, запустите и убедитесь, что в этом примере вызываются 
            конструктор по умолчанию и деструктор класса String.
*/