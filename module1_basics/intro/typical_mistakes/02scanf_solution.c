/*
    В функцию scanf вторым аргументом нужно передавать не саму переменную, а её адрес.
    Потому что для scanf не нужно значение самой переменной, 
    но ему нужен адрес переменной, чтобы знать куда нужно записывать новое значение.

    Что найти адрес переменной нужно перед ней поставить значок  &  (амперсанд)

        scanf("%i", &a);
                    ▲
                    | 
                 вот тут


    Если вы не поставите амперсанд и напишите так:

        scanf("%i", a);

    то это будет означать, что вы просите записать считанное значение по адресу равному a (то есть 0, так как a = 0)
    Ячейка памяти с адресом 0 используется операционной системой и вы туда писать ничего не имеете права.

    Вся память делится на сегменты. Некоторые сегменты вы можете использовать, а некоторые нет.
    Ячейка памяти с адресом 0 лежит в сегменте памяти, который вы не можете использовать.
    Если вы пытаетесь в эту ячейку что-то записать, то возникнет ошибка, называемая как:

        Segmentation Fault

*/

#include <stdio.h>

int main()
{
    int a = 0;
    scanf("%i", &a);

    printf("%i\n", a * a);
}