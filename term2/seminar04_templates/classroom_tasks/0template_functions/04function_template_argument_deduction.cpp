/*
    Автоматический вывод типа в шаблонных функциях

    Компилятор может сам догадаться какой тип подставить в шаблонную функцияю по типу аргументов.
    Если мы в программе вызовем функцию вот так:

        getMax(5, 10)

    То компилятор сам догадается, что нужно создать и вызвать в этом месте getMax<int>.
    Если мы в программе вызовем функцию вот так:

        std::string a = "Cat";
        std::string b = "Dog";
        getMax(a, b);

    То компилятор сам догадается, что нужно создать и вызвать в этом месте getMax<std::string>.


    Однако нужно соблюдать осторожность. Если мы напишем вот так:

        getMax("Cat", "Dog")

    То компилятор посмотрит на типы аргументов и увидет, что они равны const char[4].
    Так как массивы передаются в функции по указателю, то компилятор создаст в этом случае 
    функцию  getMax<const char*>  и будет сравнивать объекты "Cat" и "Dog" по адресу в памяти.
    Что может привести к трудно выявляемым ошибкам.
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
    cout << getMax(5.9, 1.7) << endl;   // Сгенерирует функцию getMax(double, double)

    cout << getMax(5, 10) << endl;      // Сгенерирует функцию getMax(int, int)

    cout << getMax("Cat"s, "Dog"s) << endl; // Сгенерирует функцию getMax(std::string, std::string)


    cout << "Comparing pointers:" << endl;
    cout << getMax("Cat", "Dog") << endl;   // Сгенерирует функцию getMax(const char*, const char*)
                                            // Будет сравнивать указатели, то есть больше будет строка которая лежит
                                            // в памяти по большему адресу. Скорей всего это не то, что мы хотим.
}