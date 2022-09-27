/*

    Здравствуйте

    Это первый файл кода в этом курсе программирования. В этом семестре будет использоватся язык программирования C.
    
    Почему C?

    Язык C это возможно самый влиятельный язык в истории программирования.
        Он появился в 1972 году и повлиял на многие языки, который появились после него,
        такие как C++, C#, Java и многие другие. После изучения C, вам будет проще изучать другие языки.
        
    Язык C популярный
        Несмотря на 'старость', язык C сейчас является одним из самых популярных языков программирования.
        Многие проекты, в том числе новые, до сих пор пишутся на языке C.

    Язык C компактный
        Он содержит в себе относительно немного языковых конструкций и весь синтаксис языка вполне можно 
        изучить за один семестр.

    Язык C быстрый
        Язык позволяет писать код, который будет работать так быстро, насколько это возможно.
        На других языках сложно написать код, который будет так же быстр, как код на языках C и C++.


    Язык C является основой для языка C++
        C++ был создан на основе языка, поэтому первый шаг для полноценного изучения языка C++ это изучение языка C.
        Несмотря на это, это разные языки. В язык C++ было добавлено так много новых возможностей по сравнению с C,
        что код на C++ обычно выглядит совершенно по другому.
        C++ это гораздо более сложный язык, требующий для изучения хорошего знания C.



    Этот файл является файлом исходного кода на языке C и содержит текст простой программы, печатающей на экран строку Hello World!

    Задание:

        Скомпилируйте и запустите эту программу. Для этого вам нужно сделать следующее:

            1)  перейти в Терминале в эту папку (папка называется 0hello)
                используйте команду cd, чтобы перейти в нужную папку

                cd путь_до_папки


            2)  Скомпилировать программу написав в Терминале
                
                gcc 01hello.c


            3)  Запустить скомпилированную программу, написав в Терминале:

                ./a.out      (на Linux)              a.exe       (на Windows)

*/



#include <stdio.h>

int main() 
{
    printf("Hello World\n");
}