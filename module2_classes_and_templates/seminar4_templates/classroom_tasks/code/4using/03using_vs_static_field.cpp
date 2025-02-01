/*
    using алиасы внутри классов

    
    При использовании классов с определёнными внутри алиасами внутри шаблонных функций и классов возникают некоторые
    сложности. Рассмотрим следующий код:

        class House 
        {
        public:
            using dog = int;
        };


        class Shelter 
        {
        public:
            using dog = std::string;
        };


        template <typename T>
        void f(T::dog x)
        {
            T::dog a = x + x;
            cout << a << endl;
        }

    В этом примере создана шаблонная функция f, которая предполагает, что у типа T должен быть внутри алиас под 
    названием dog. Например, в функции f<House> тип T::dog будет int, а в функции f<Shelter> тип T::dog будет std::string.


    Однако, данный код не скомпилируется. Причина этого заключается в том, что внутри шаблонной функции f
    невозможно определить что такое T::dog - имя типа или название статического поля. Ведь, если в качестве типа T
    будет тип, у которого есть алиас по имени dog, то функция f написана корректно, а если в качестве типа T
    выступает тип, у которого есть статическое поле по имени dog, то шаблонная функция f не должна скомпилироваться.

    По умолчанию, компилятор в таких случаях считает, что это статическое поле. То есть в функции f, определённой
    выше, компилятор будет считать, что T::dog - это статическое поле. Естественно такая функция не скомпилируется.

    Чтобы указать, что T::dog является именно названием типа, а не статическим полем нужно написать typename T::dog.
    То есть:

        T::dog              -   статическое поле по имени dog внутри класса T
        typename T::dog     -   имя типа по имени dog внутри класса T

    Соответственно, правильная версия функции f выглядит так:


        template <typename T>
        void f(typename T::dog x)
        {
            typename T::dog a = x + x;
            cout << a << endl;
        }
*/


#include <iostream>
#include <string>
using std::cout, std::endl;


class House 
{
public:
    using dog = int;
};


class Shelter 
{
public:
    using dog = std::string;
};


class Test 
{
public:
    static const int dog = 100;
};



template <typename T>
void f(typename T::dog x)
{
    typename T::dog a = x + x;
    cout << a << endl;
}


template <typename T>
void g()
{
    cout << T::dog << endl;
}



int main()
{
    f<House>(100);
    f<Shelter>("Alice");

    g<Test>();
}

