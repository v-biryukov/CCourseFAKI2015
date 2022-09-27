#include <stdio.h>


int combainer(int a)
{
    int b;
    scanf("%i", &b);

    printf("%i\n", a + b);

    return a * b;
}



int main()
{
    printf("%i\n", combainer(5));
}

/*
    Скомпилируйте эту программу и запустите. Программа потребует ввести число.
    Если, например, ввести число 10, то программа напечатает

        15
        50

    Разберёмся подробней, что происходит в этой программе:

        1)  Мы заходим в функцию main так как любая программа начинается с функции main

        2)  Пытаемся исполнить строку

                printf("%i\n", combainer(5));

            Чтобы испольнить эту строку нужно вычислить значение combainer(5), поэтому мы заходим
            в функцию combainer, при этом внутри этой функции a будет равно 5.

        3)  Внутри функции combainer мы заводим переменную b и считываем её с экрана.
            В это время программа просит ввести число на экране.

        4)  После того как число считано с экрана (предположим, что мы ввели число 10) мы печатаем 
            сумму чисел a и b (то есть число 15)

        5)  Затем мы заканчиваем функцию и возвращаем a * b  (то есть возвращаем число 50)

        6)  Мы вернули число 50 из функции combiner, поэтому за место combainer(5) подставится число 50.
            То есть строка:

                printf("%i\n", combainer(5));

            Превратится в строку:

                printf("%i\n", 50);

            и на экран напечатается число 50.
*/