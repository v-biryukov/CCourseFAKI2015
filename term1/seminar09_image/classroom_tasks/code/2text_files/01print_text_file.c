/*
    Печать в текстовый файл, функция fprintf.

    Для того, чтобы записать какой-нибудь текст в файл, можно воспользоваться функцией fprintf.
    Функция fprintf очень похожа на функцию printf, только первым аргументом в эту функцию передаётся
    указатель на структуру FILE. После этого нужно передать те же аргументы, что и в функцию printf.

    Например, чтобы напечатать в файл строку "Hello file!" нужно написать:
        
        fprintf(file, "Hello file!\n");

    А чтобы напечатать в файл число, содержащееся в переменной a типа int, нужно написать:

        fprintf(file, "%i\n", a);
*/

#include <stdio.h>

int main()
{
    FILE* file = fopen("hello.txt", "w");

    fprintf(file, "Hello file!\n");

    int a = 123;
    fprintf(file, "%i\n", a);

    fclose(file);
}

/*
    Задачи:

        1)  Запустите данную программу. Убедитесь, что после её запуска был создан файл hello.txt.
            Что содержит данный файл?

        2)  Пусть у нас есть массив чисел типа float:

                float numbers[] = {5.2, 1.5, 2.1, 0.4, 7.2};

            Измените программу так, чтобы в файл hello.txt записывались ещё и эти числа.
*/