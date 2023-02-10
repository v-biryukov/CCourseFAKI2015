/*
    std::span

    Шаблонный класс std::span это аналог класса std::string_view, но для вектора

        std::string     <-->   std::string_view
        std::vector<T>  <-->   std::spat<T>

    Он позволяет передавать элементы более эффективно, чем передача по ссылке.
    Внутри себя объекты этого класса содержат 2 поля: указатель на данный и размер "окошка".
    
    !!  В отличии от string_view класс span может менять элементы.
        Чтобы передать span, который не будет менять элементы нужно передавать span от const T:

            void func(std::span<const int> sp)

        Также как string_view, функции должны принимать объекты класса span по значению.


    В функции, принимающие std::span, можно передавать как вектора(std::vector), так и массивы(std::array).
*/

#include <iostream>
#include <vector>
#include <span>
#include <string>
using std::cout, std::endl;


void printElements(std::span<const int> sp)
{
    for (int i = 0; i < sp.size(); ++i)
        cout << sp[i] << " ";
    cout << endl;
}


void inc(std::span<int> sp)
{
    for (int i = 0; i < sp.size(); ++i)
        sp[i]++;
}


int getMax(std::span<int> sp)
{
    int result {sp[0]};
    for (int i = 1; i < sp.size(); ++i)
    {
        if (sp[i] > result)
            result = sp[i];
    }
    return result;
}



int main()
{
    std::vector<int> v {10, 20, 30, 40, 50};
    std::array<int, 5> a {10, 20, 30, 40, 50};

    inc(v);
    inc(a);

    printElements(v);
    printElements(a);

    cout << getMax(v) << endl;
    cout << getMax(a) << endl;
}