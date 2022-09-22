/*
    Указатель как итератор

    Если мы воспользуется арифметикой указателей, то можем написать цикл, в котором за место целой переменной i,
    будем использовать указатель p.

    Ведь при прибавлении к указателю 1, он начинает указывать на следующий элемент массива.
    Цикл остановится, когда  p - a  сравняется с размером массива.
    Массив a в выражении  p < a + 6  будет восприниматься как указатель на первый элемент массива.
    Соответственно, a + 6 будет 
*/

#include <stdio.h>



int main()
{
    int a[6] = {10, 20, 30, 40, 50, 60};
    
    for (int* p = &a[0]; p < a + 6; ++p)
    {
        printf("%i ", *p);
    }
    printf("\n");
}


/*
    Задача:

        Напишите функцию inc из прошлого файла, используя внутри этой функции цикл, где в качестве итератора будет
        использоваться указатель int*

*/