/*
    Новое имя типа

    В языке C существует возможность вводить новое имя для уже существующего типа с помощью ключевого слова typedef.
    Чтобы ввести новое имя для типа нужно написать следующее:

        typedef староеимя новоеимя;

    После этого для типа можно будет использовать и новое и старое имя.
    Например, мы можем написать так:

        typedef int dog;

    и после этого использовать dog как будто это int.
*/

#include <stdio.h>

typedef int dog;

int main()
{
    dog a = 10;
    dog b = 20;

    printf("%i\n", a + b);
}

/*
    Задача:

        Создайте новое имя типа для long long и назовите его ll (для краткости).
        После этого создайте 2 переменные типа ll и считайте их, используя scanf.
        Напечатайте произведение этих двух чисел.
*/