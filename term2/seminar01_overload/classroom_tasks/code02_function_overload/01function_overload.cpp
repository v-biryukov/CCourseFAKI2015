#include <cstdio>

/*
    В отличии от C, в C++ можно создать несколько функций с одним и тем же названием, 
    но с разными типами аргументов
*/


void print(int x) 
{
    printf("Int: %d\n", x);
}


void print(float x) 
{
    printf("Float: %f\n", x);
}


void print(double x) 
{
    printf("Double: %lf\n", x);
}



int main() 
{
    int a = 15;
    float b = 4.214;

    // Компилятор сам поймёт, какую функцию нужно вызвать
    print(a);
    print(b);
    print(7.3);


    /*
        Задания:

        1) Переопределите функцию print для строки в стиле C (char[])
        
        2) Переопределите функцию print для структуры:
            struct Book 
            {
                char title[50];
                float price;
                int pages;
            };

    */
}