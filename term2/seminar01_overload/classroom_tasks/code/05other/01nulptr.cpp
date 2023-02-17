/*
    Новое специальное нулевое значение для указателя: nullptr
    В языке C для этой цели использовался NULL, который был просто числом 0

    Если определить NULL так:  

        #define NULL (void*)0

    То, в отличии от языка C, в языке C++ простая строка вида:

        int* p = NULL;

    не сработает, так как слева стоит int* а справа void* 

    
    Если определить NULL так:  

        #define NULL 0

    то в C++ могут возникнуть проблемы с перегрузкой, как это показано ниже.
*/

#include <cstdio>

void print(int value) 
{
    printf("Int: %d\n", value);
}

void print(void* pointer) 
{
    printf("Pointer: %p\n", pointer);
}

int main() 
{
    void* p1 = NULL;
    void* p2 = nullptr;

    // Всё ОК (компилятор может выбрать функцию):
    print(p1);
    print(p2);

    // Тут неверно (компилятор не может выбрать перегруженную функцию, произойдёт ошибка):
    print(NULL);

    // Тут всё OK:
    print(nullptr);
}