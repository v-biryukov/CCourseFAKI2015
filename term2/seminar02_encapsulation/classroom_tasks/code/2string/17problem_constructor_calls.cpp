/*
    Различный синтаксис вызова конструкторов
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



int main() 
{
    String a = "Cat";

    String b = String("Dog");

    String c("Mouse");

    String d = {"Tiger"};

    String e = String{"Axolotl"};

    String f {"Lion"};
}

/*
    Ввиду того, что язык C++ имеет длинную историю, на протяжении которой в язык добавлялись новые возможности,
    в языке существует множество способов сделать одно и то же разными способами.

    Один из ярких примеров этого является инициализация объекта. В этом примере создаются 6 строк. Синтаксис различается, 
    но в данном случае все эти строки по сути делают одно и то же: cоздают объект с помощью конструктора от const char*.
    При этом не вызывается никаких конструкторов копирования или операторов присваивания.

    В современном языке C++ предпочтительным способом инициализации является вариант f:

        String f {"Lion"};



    Задачи:

        1)  Что напечатает данная программа?
            В каком порядке вызовутся конструкторы и в каком порядке вызовутся деструкторы?

        2)  Скомпилируйте программу и запустите, чтобы проверить ваши догадки.

        3)  Создайте 5 объектов типа String с помощью конструктора по умолчанию, используя разный синтаксис вызова конструктора.

        4)  Пусть есть объект x типа String:

                String x = "Cat";

            Создайте 6 объектов типа String с помощью конструктора копирования, используя разный синтаксис вызова конструктора.
            Все новые объекты должны копировать объект x.

*/