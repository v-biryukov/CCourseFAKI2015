/*
    Строгие правила алиасинга и оптимизация

    Однако если типы указателей различны и не попадают под исключения строгих правил алиасинга,
    то оптимизацию можно сделать.
    Компилятор всегда полагает, что программа следует строгим правилам алиасинга, а, следовательно, в программе никогда
    не может возникнуть ситуация, когда указатели int* и float* указывают на одни и те же данные.

    Таким образом в этой программе компилятор может сделать следующую оптимизацию:
    Заменить функцию:

        int func(int* p, float* q)
        {
            int temp = *p;

            *q = 0;

            return temp - *p;
        }

    На функцию:

        int func(int* p, float* q)
        {
            *q = 0;

            return 0;
        }

    
    Но если вы передадите на вход функции два одинаковых адреса на объект типа int, то это приведёт
    к неопрделённому поведению.

    Если скомпилировать эту программу без оптимизации:

        gcc 13aliasing_rule_optimization.c

    и запустить, то программа скорей всего напечатает 10, так как компилятор не оптимизировал функцию.

    Но если скомпилировать эту программу с оптимизациями: 

        gcc -O3 13aliasing_rule_optimization.c

    и запустить, то программа скорей всего напечатает 0, так как функция была оптимизирована.

*/

#include <stdio.h>


int func(int* p, float* q)
{
    int temp = *p;

    *q = 0;

    return temp - *p;
}



int main()
{
    int a = 10;

    printf("%i\n", func(&a, (float*)&a));
}


/*
    Задачи:

        1)  Скомпилируйте данную программу без оптимизаций и с уровнем оптимизации -O3.
            Проверьте что будет выдавать программа в обоих случаях.

        2)  Найдите с какого уровня оптимизации включается оптимизация строгого алиасинга.


        3)  Если заменить float* на unsigned int*, то будет ли работать эта оптимизация?

        4)  Если заменить float* на char*, то будет ли работать эта оптимизация?

        5)  Если заменить float* на long long*, то будет ли работать эта оптимизация?

        6)  Если заменить float* на long*, то будет ли работать эта оптимизация?

        7)  Можно отдельно выключить эту оптимизацию с помощью флага -fno-strict-aliasing.
            То есть скомпилировав вот так:

                gcc -O3 -fno-strict-aliasing 13aliasing_rule_optimization.c

            можно включить все оптимизации, кроме оптимизации строгого алиасинга.
            Протестируйте этот флаг.
*/