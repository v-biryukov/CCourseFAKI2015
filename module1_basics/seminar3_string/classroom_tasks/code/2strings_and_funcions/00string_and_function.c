/*
    Передача строк в функции

    Так как строки по сути являются массивами, то и в функции они передаются как массивы.
    То есть они НЕ копируются в функции, а вместо этого в функцию передаётся адрес первого элемента.
    Поэтому, если мы поменяем строку внутри функции, то она изменится и снаружи.
    
    Чтобы передать строку в функцию func нужно написать:
        
        void func(char str[])

    или

        void func(char str[100])

    или

        void func(char* str)   // Об указателях будет больше в следующем семинаре

    Все эти 3 варианта делают одно и то же, а именно, передают в функцию адрес первого элемента строки.
    В этом семинаре будем использовать первый вариант.
*/



#include <stdio.h>

void func(char str[])
{
    str[0] = 'P';
}


int main()
{
    char str[100] = "Cats and dogs";

    func(str);

    printf("%s\n", str);
}



/*
    Задачи:

        1)  Что напечатает данная программа?

        2)  Напишите функцию change_letter(char str[], char from, char to), которая будет менять
            все символы равные from на символы to.

                char str[100] = "Cats and dogs";

                change_letter(str, 'a', 'o');
                change_letter(str, 's', 'i');
                printf("%s\n", str);

            Этот код должен напечатать

                Coti ond dogi
*/