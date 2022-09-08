/*
    Рассмотрим при каких условиях происходит вызов того или иного метода.

    Для этого будем использовать класс String, в котором была добавлена печать на экран для конструкторов, 
    деструктора и оператора присваивания.
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



int main() 
{
    String a = "Cat";
    String b = a;
}

/*
    Задачи:

        1)  Какие методы вызовутся в строке

                String a = "Cat";

            Выберите один из вариантов:

                а)  Только конструктор из const char*
                б)  Только оператор присваивания
                в)  И конструктор из const char* и оператор присваивания


        2)  Какие методы вызовутся в строке

                String b = a;

            Выберите один из вариантов:

                а)  Только конструктор копирования
                б)  Только оператор присваивания
                в)  И конструктор копирования и оператор присваивания



        3)  Проверьте ваши догадки скомпилировав и запустив программу

*/