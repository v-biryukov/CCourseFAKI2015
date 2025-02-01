/*
    Разные варианты синтаксиса объявления указателей


    Если вы посмотрите код, написанный другими программистами, то увидите, что разные программисты
    используют разный синтаксис при объявлении указателя.
    Грубо говоря, разные программисты ставят звёздочку в разных местах при объявлении указателей.

    
    Допустим мы хотим создать указатель типа int*.
    Есть 3 распространённых варианта:

        int* p;                  int *p;                   int * p;

    Все эти 3 способа делают одно и то же, а именно создают переменную типа  int*  по имени p.
    Преемущества и недостатки каждого из этих методов:

        1)  int* p;

            Преемущества:

                Пишем именно то, что происходит.
                Мы тут пишем, что создаём переменную типа  int*  по имени p, это именно то, что происходит.
                Самый понятный способ, значит, если вы будете использовать этот способ, то и ваш код будет более понятным.

            Недостатки:

                Можно ошибиться при объявлении нескольких указателей в одной строке.
                Не очень удобно объявлять указатели на функции.



        2)  int *p;

            Преемущества:

                Удобнее объявлять несколько указателей в одной строке.
                Удобнее объявлять указатели на функции.

            Недостатки:

                Пишем не то, что происходит.
                Кажется что мы тут создаём переменную типа int, по имени *p, но это не то, что происходит.
                В результате ваш код будет менее понятным.



        3)  int * p;

            Преемущества:

                Нет 

            Недостатки:

                Совмещает в себе недостатки двух предыдущих способов.



    Рекомендации хорошего стиля от создателей языков:

        В языке C нет рекомендаций от создателей языка, какой способ использовать.
        Большинство программистов используют или 1-й или 2-й способ.


        В языке C++ есть рекомендация от создателей языка (называется C++ Core Guidelines).
        Рекомендуется использовать 1-й способ.



    В этом курсе будет использоваться 1-й способ, а также правило хорошего стиля, которое запрещает
    объявлять несколько указателей в одной строке.

*/

#include <stdio.h>

int main()
{
    int* p;

    int *q;

    int * r;

    printf("%zu\n", sizeof(p));
    printf("%zu\n", sizeof(q));
    printf("%zu\n", sizeof(r));
}