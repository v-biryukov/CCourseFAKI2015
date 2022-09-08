/*
    Неявное приведение типа с помощью конструктора от одного параметра.
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

    String(const char* s) 
    {
        cout << "String Constructor from const char*  (" << s << ")" << endl;

        size_t i = 0;
        while (s[i] != '\0')
            i++;
        mSize = i;
        mCapacity = i + 1;

        mpData = (char*)std::malloc(sizeof(char) * mCapacity);

        for (size_t i = 0; s[i]; ++i)
            mpData[i] = s[i];
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



void print(String s)
{
    cout << s << endl;
}


int main() 
{
    String a;
    a = "Dog";

    print("Mouse");
}



/*
    Одна из скрытых вещей, где используются конструкторы, это для неявного приведения типов.

    Рассмотрим следующие строки:

        String a;
        a = "Dog";

    Во второй строке должен вызваться оператор присваивания. 
    Слева от оператора присваивания стоит объект типа String, а справа от оператора присваивания стоит объект типа  const char[4].
    Поэтому должен вызваться метод  operator=(const char* s) класса String. (при передаче в функцию массив автоматически конвертируется в указатель)
    Но такого метода в классе String нет. Что же тогда будет сделано?

    В этом случае будет сделано следующее:

        1)  Будет создан временный объект типа String с использованием конструтора  String(const char* s).
        2)  Будет вызван оператор присваивания operator=(const String& s). Объекту a присвоится временный объект.
        3)  Временный объект будет уничтожен, при этом вызовется деструктор класса String.




    Рассмотрим строку:

        print("Mouse");

    Функция print должна принимать объект типа String, но на вход ей приходит объект типа  const char[6].
    Что будет сделано в этом случае?
    И в этом случае всё сработает, так как объект  s  функции print будет создан с помощью конструктора класса String от const char*.


    
    Таким образом конструктор от одного аргумента автоматически используется для неявного приведения одного типа в другой.



    Задачи:

        1)  Что если мы напишем конструктор класса String от числа типа int.
            Этот конструктор будет принимать число n и создавать строку, состоящую из n символов 'a'


                String(int n)
                {
                    cout << "String Constructor from int  (" << n << ")" << endl;

                    mSize = n;
                    mCapacity = mSize + 1;
                    mpData = (char*)std::malloc(sizeof(char) * mCapacity);
                    for (size_t i = 0; i < mSize; ++i)
                        mpData[i] = 'a';
                    mpData[mSize] = '\0';
                }

        
            
            Будет ли этот конструктор использоваться для неявного приведения чисел типа int в строки типа String?
            Например, будет ли работать следующий код:

                String b;
                b = 5;

            (b будет строкой состоящей из 5 символов 'a' ?)
    

                print(10);

            (напечатает строку, состоящую из 10 символов 'a')
*/