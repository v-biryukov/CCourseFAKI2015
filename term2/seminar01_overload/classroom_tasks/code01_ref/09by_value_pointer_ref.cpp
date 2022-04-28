#include <iostream>
using std::cout, std::endl;

/* 
    Ссылки, как и указатели используются для передачи объектов в функции
    
    Рассмотрим три функции

        inc_by_value - принимаем объект по значению
        В этом случае объект копируется и функция работает с копией

        inc_by_pointer - принимаем объект по адресу
        В этом случае внутри функции создаётся указатель, и в этот указатель
        мы передаём адрес нашего объекта

        inc_by_reference - принимаем объект по ссылке
        В этом случае происходит всё примерно то же самое, что и в случае incByPointer
        Только с гораздо более приятным синтаксисом

*/


void inc_by_value(int a) 
{
    a += 1;
}

void inc_by_pointer(int* p) 
{
    *p += 1;
}

void inc_by_reference(int& a) 
{
    a += 1;
}

int main() 
{
    int a = 10;

    cout << "1) Initial a = " << a << endl
    
    inc_by_value(a);
    cout << "2) After inc_by_value a = " << a << endl;

    inc_by_pointer(&a);
    cout << "3) After inc_by_pointer a = " << a << endl

    inc_by_reference(a);
    cout << "4) After inc_by_reference a = " << a << endl;
}


/* 
    Задание:

    1)  Напишите функции:

        cube_by_pointer(int* p)   - принимет число по указателю и возводит это число в куб
        cube_by_reference(int& a) - принимет число по ссылке и возводит это число в куб

        Протестируйте эти функции в main


    2)  Написать функции: 

        swap_by_pointer(int* pa, int* pb) - принимает 2 числа по указателю и обменивает их значения
        swap(int& pa, int& pb) - принимает 2 числа по ссылке и обменивает их значения

        Протестируйте эти функции в main
    
*/