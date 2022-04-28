#include <iostream>
using std::cout, std::endl;


/*
    Пусть у нас есть некоторый объект, например
        int a = 10;

    После того как мы создали ссылку на этот объект
        int& r = a;

    Все (почти) операции применяемые к ссылке r применяются на самом деле к объекту a
    Как будто у одного объекта теперь два имени a и r
    Поэтому можно сказать, что ссылка это новое имя для объекта

    При этом изменить саму ссылку (например, чтобы она начала указывать на другое имя) нельзя
*/

int main() 
{
    int a = 10;
    int& r = a;


    r += 5;                     // Прибавим к a число 5
    r *= 2;                     // Умножим a на 2
    cout << r << endl;          // Напечатаем a
    cout << sizeof(r) << endl;  // Напечатаем размер a
    cout << &r << endl;         // Напечатаем адрес a
}


/*
    Задачи:

    1)  Чему будет равно значение a в конце этой программы


*/