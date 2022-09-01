#include <iostream>
using std::cout, std::endl;

/* 
    Ссылки, как и указатели используются для передачи объектов в функции
    
    Рассмотрим три функции

        incByValue - принимаем объект по значению
        В этом случае объект копируется и функция работает с копией

        incByPointer - принимаем объект по адресу
        В этом случае внутри функции создаётся указатель, и в этот указатель
        мы передаём адрес нашего объекта

        incByReference - принимаем объект по ссылке
        В этом случае происходит всё примерно то же самое, что и в случае incByPointer
        Только с гораздо более приятным синтаксисом

*/


void incByValue(int a) 
{
    a += 1;
}

void incByPointer(int* p) 
{
    *p += 1;
}

void incByReference(int& a) 
{
    a += 1;
}

int main() 
{
    int a = 10;

    cout << "1) Initial a = " << a << endl
    
    incByValue(a);
    cout << "2) After incByValue a = " << a << endl;

    incByPointer(&a);
    cout << "3) After incByPointer a = " << a << endl

    incByReference(a);
    cout << "4) After incByReference a = " << a << endl;
}


/* 
    Задание:

    1)  Напишите функции:

        cubeByPointer(int* p)   - принимет число по указателю и возводит это число в куб
        cubeByReference(int& a) - принимет число по ссылке и возводит это число в куб

        Протестируйте эти функции в main


    2)  Написать функции: 

        swapByPointer(int* pa, int* pb) - принимает 2 числа по указателю и обменивает их значения
        swap(int& pa, int& pb) - принимает 2 числа по ссылке и обменивает их значения

        Протестируйте эти функции в main
    
*/