/*
    Создадим строку, которая при создании (т.е в конструкторе) будет автоматически выделять необходимую память в Куче.
    В чём-то реализация этой строки будет похожа на реализацию динамического массива из прошлого семестра.

    У класса строки 3 поля:

        mSize       -   размер - количество символов в строке (без учёта \0)
        mCapacity   -   вместимость - количество выделенной памяти в Куче
        mpData      -   указатель на выделенную память в Куче. В этой памяти строка будет иметь такой же вид,
                        как и строка языка C. В частности она будет иметь символ '\0' на конце. 
                        Символ '\0' на конце для нашей строки теперь не нужен, так как мы будем хранить размер строки. 
                        Но мы его оставим, чтобы было удобно конвертировать нашу строку в строку в стиле C.

    
    Размер и вместимость это разные величины.

        Например, для хранения строки "Cat" может быть выделено памяти под 10 символов, хоть и под эту строку было бы
        достаточно всего 4. Представьте, что у вас есть длинная строка и вы хотите удалить последний символ в ней.
        Если бы мы не хранили вместимость, а всегда выделяли памяти впритык, то в этом простом случае нам бы пришлось
        перевыделять память и копировать всю строку в новую память. Если же мы храним вместимость, то достаточно всего 
        лишь уменьшить размер на 1 и поставит \0 в новый конец строки.



    Теперь создадим конструктор, который будет выделять память и заполнять его нужным образом
        
        Конструктор   String(const char* str)   конструирует нашу строку из строки в стиле C.
        Принимаем на вход именно константную строку, так как в этом случае в конструктор можно будет передать как 
        константные, так и неконстантые строки. Если бы мы написали так   String(char* str), то в конструктор нельзя 
        было бы передать константные строки.


        В строках:

            size_t i = 0;
            while (str[i] != '\0')
                i++;
            mSize = i;
            mCapacity = i + 1;

        мы находим размер переданной строки (strlen не используем, чтобы не связываться со старой библиотекой).
        Вместимость на 1 больше, так как нужно учесть память под символ /0.


        В строке:

            mpData = (char*)std::malloc(sizeof(char) * mCapacity);

        выделяем необходимую память.


        В строках:

            for (size_t i = 0; str[i] != '\0'; i++)
                mpData[i] = str[i];
            mpData[mSize] = '\0';
    
        копируем содержимое переданной строки в только что выделенную память.


    Другие методы класса String:

        getSize     - возвращает размер строки.
        getCapacity - возвращает вместимость строки.
        cStr        - возвращает строку в стиле C, то есть указатель на массив из char-ов с конечным символом \0.
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


std::ostream& operator<<(std::ostream& out, const String& s) 
{
    out << s.cStr();
    return out;
}


int main() 
{
    String a = "Cat";
    String b = "Dog";
    String c = "Lion";   

    cout << a << endl << b << endl << c << endl;
}


/*  
    Задание:

    1) Создайте конструктор String(), который будет создавать пустую строку
            (mSize = 0, mCapacity = 1, строка mpData содержит в себе 1 символ ('\0'))

        Конструктор, который не принимает аргументов называется конструктором по умолчанию.


    2) Создайте конструктор String(size_t n, char a), который будет создавать строку из n символов a
            (mSize = n, mCapacity = n + 1, строка mpData содержит в себе n + 1 символ (n раз a и '\0'))


    2) Создайте конструктор String(const String& s), который будет создавать строку String из другой строки String
            (mSize = s.mSize, mCapacity = s.mCapacity, строка mpData содержит в себе копию строки s.mpData)

        Конструктор, который создаёт объект по другому объекту такого же типа называется конструктором копирования.


    Протестируйте эти конструкторы:
    
        String a;
        cout << a << endl;

        String b(10, 'q');
        cout << b << endl;

        String c("Cat");
        cout << c << endl;

        String d(c);
        cout << d << endl;
*/
