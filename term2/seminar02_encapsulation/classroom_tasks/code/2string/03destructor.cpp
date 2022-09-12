/*
    В конструкторе мы выделили память с malloc, но нигде в программе её не освободили
    Соответственно, в предыдущей программе у нас есть очень серьёзная ошибка - утечка памяти.
    
    Где же нужно освобождать память?
    Если память была выделена в конструкторе при создании объекта, то выделять её нужно при удалении объекта.
    Для того, чтобы испольнить ваш код при удалении объекта существует специальный метод, который называется Деструктор.
    

    Деструктор - это специальный метод, который вызывается тогда, когда объект уничтожается
    Объекты, созданные на стеке удаляются при выходе из области видимости


    Синтаксис деструктора такой:

        ~String()
        {
            ...
        }
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
        cout << "Constructor of " << str << endl;
        size_t i = 0;
        while (str[i] != '\0')
            i++;
        mSize = i;
        mCapacity = i + 1;

        mpData = (char*)std::malloc(sizeof(char) * mCapacity);

        for (size_t i = 0; str[i] != '\0'; i++)
            mpData[i] = str[i];
        mpData[mSize] = '\0';
    }


    ~String()
    {
        cout << "Destructor of " << mpData << endl;
        std::free(mpData);
    }


    size_t getSize() const 
    {
        return mSize;
    }

    size_t getCapacity() const 
    {
        return mCapacity;
    }

    const char* cStr() const 
    {
        return mpData;
    }
};


std::ostream& operator<<(std::ostream& left, const String& right) 
{
    left << right.cStr();
    return left;
}


int main() 
{
    String a = "Cat";
    String b = "Dog";
      
    if (true)
    {
        String c = "Lion"; 
    }

    String c = "Bear";
}



/* 
    Задание:
    
        1)  Что напечатает данная программа?
            В каком порядке вызовутся конструкторы и деструкторы

        
        2)  Если создать строку String в цикле, то будут ли каждую итерацию вызываться конструкторы и деструкторы?

            for (int i = 0; i < 10; ++i)
            {
                String s = "Elephant";
            }
*/
