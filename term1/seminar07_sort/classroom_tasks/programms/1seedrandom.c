#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{ 
    // Задаём первое число последовательности псевдослучайных чисел
    srand(time(0));
    // time(0) - возвращает число секунд, прошедших с 00:00 1 января 1970
    // Теперь при каждом вызове программы числа будут разными
    // (если, конечно, программа не была вызвана 2 раза за одну и ту же секунду)
    

    printf("Random number = %d (from 0 to %d)\n", rand(), RAND_MAX);

    int a = rand() % 10;
    printf("Random number (from 0 to 9) = %d\n", a);
    

    float x = (float)rand() / RAND_MAX;
    printf("Random float number (from 0 to 1) = %f\n", x);


    int c = rand() * (RAND_MAX + 1) + rand();
    printf("Random number = %d (from 0 to %llu)\n", c, RAND_MAX * RAND_MAX);
}