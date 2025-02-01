/*
    Решение проблемы с помощью шаблона функций

    Мы можем написать такой шаблон:
    
        template <typename T>
        T getMax(T a, T b) 
        {
            if (a > b)
                return a;
            else
                return b;
        }
        
    Теперь, если мы в программе вызовем функцию вот так:

        getMax<float>(2.5f, 1.2f);

    То во время компиляции по шаблону getMax сгенерируется функция getMax<float>, похожая на шаблон,
    но только за место T везде подставится float. Эта функция и будет вызываться в данном случае.

    Функция getMax будет работать для любого типа с объектами которого можно делать следующее:

        1)  Применять оператор >

        2)  Копировать. Так как передача в функцию getMax осуществляется по значениию,
            то объекты должны уметь копироваться.

    То есть шаблонная функция getMax может быть применена к объектам базовых типов либо к объектом классов,
    у которых реализованы operator> и конструктор копирования.
*/


#include <iostream>
#include <string>
using std::cout, std::endl;
using namespace std::string_literals;

template <typename T>
T getMax(T a, T b) 
{
    if (a > b)
        return a;
    else
        return b;
}

int main() 
{
    cout << getMax<int>(5, 10) << endl;

    cout << getMax<double>(5.9, 1.7) << endl;

    cout << getMax<std::string>("Cat"s, "Dog"s) << endl;
}