/*
    Оператор присваивания

    Оператор присваивания можно сделать только в виде метода
    Такой метод должен 
        - принимать один аргумент - это правый аргумент оператора присваивания, 
        - менять объект, вызвавший оператор (то есть левый аргумент оператора присваивания)
        - возвращать ссылку на объект, вызвавший оператор (то есть объект слева от оператора присваивания)


    Почему оператор присваивания должен возвращать ссылку на левый аргумент? 
    Чтобы оператор присваивания работал аналогично тому как работает оператор присваивания для обычных типов 
    
        Рассмотрим следующий пример:

            int a, b, c;
            a = b = c = 123;  // все переменные станут равны 123, операторы выполняются справа налево

            (a = 1) = 2;      // a станет равной 2


        Мы хотим, чтобы и такой код работал:

            String a, b, c;
            a = b = c = "Cat";

            (a = "Dog") = "Mouse";


    Прототип оператора присваивания как метода класса String должен выглядеть так:

        String& operator=(const String& b)
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
        // Ваш код нужно написать здесь
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
    String b = "Mouse";
    String c;

    a = b;
    cout << a << endl;

    a = b = c = "Elephant";
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    (a = "Dog") = "Axolotl";
    cout << a << endl;

    a = a;
    cout << a << endl;
}



/* 
    Задание:

        1)  Написать оператор присваивания для строки String в виде метода класса String

            Не забудьте учесть случай:

                String a = "Cat";
                a = a;
*/
