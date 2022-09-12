/*
    Операторы сравнения  ==  !=  >  >=  <  <=

    К строкам можно применять операторы сравнения.

    Очевидно, когда строки равны: должны быть равны размеры строк (mSize) и все символы от 0 до mSize
    При этом вместимость (mCapacity) у равных строк может отличаться

    Как сравнивать строки на больше/меньше? В этом случае сравниваем лексикографически, то есть, по алфавиту.
    То слово, которое находилось бы в орфографическом словаре позже и будет большим.
    Например,  "Cat" > "Camel"  так как первые 2 буквы совпадают, а третья буква у слова Cat идёт дальше по алфавиту


    Более точное сравнение такое: мы сравниваем посимвольно до первого несовпадающего символа
    Если мы нашли первые несовпадающий символ и не дошли до конца в обоих строках, то та строка будет больше,
    у которой код этого символа будет больше.

*/

#include <iostream>
#include <iomanip>
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

    String& operator=(const String& right)
    {
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
    cout << std::boolalpha;

    String a = "Cat";
    String b = "Camel";

    cout << (a > b) << endl;
    cout << (a < b) << endl;
    cout << (a == b) << endl;
    cout << (a == a) << endl;


    String c = "Catharsis";

    cout << (a > c) << endl;
    cout << (a < c) << endl;
    cout << (a == c) << endl;
    cout << (a != c) << endl;
}



/*
    Задача:

        1)  Напишите операторы  ==  !=  >  >=  <  <=  для класса String
            Подсказка:  можно использовать уже написанные сравнения
            Например, если вы написали оператор > , то очень просто написать оператор <= , используя оператор >

*/