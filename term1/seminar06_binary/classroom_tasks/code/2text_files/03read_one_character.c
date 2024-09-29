/*
    Чтение одного символа из файла. Функция fgetc.
    

    Функция fgetc читает ровно один символ из файла и возвращает его код ASCII.
    Следующий вызов функции fgetc прочитает следующий символ и т. д.

    Обратите внимание, что функция fgetc возвращает объект типа int, а не char.
    Это связано с тем, что функция fgetc на самом деле может использоваться не только для текстовых файлов,
    но вообще для любых файлов. В общем случае она возвращает значение следующего байта файла.
    Байт произвольного файла может принимать значения в диапазоне от 0 до 255. Также нужно возвращать какое-то 
    значение вне этого диапазона, чтобы сигнализированть о том, что мы дошли до конца файла.
    Поэтому использовать тип char или unsigned char для возвращаемого значения не получится.

    Если мы находимся в самом конце файла, то при вызове функция fgetc вернёт специальное значение, равное
    константе EOF (EOF это сокращения для End Of File).
*/

#include <stdio.h>

int main()
{
    FILE* file = fopen("animals.txt", "r");


    int c = fgetc(file);
    printf("%c\n", (char)c);


    printf("%c\n", (char)fgetc(file));
    printf("%c\n", (char)fgetc(file));


    fclose(file);
}


/*
    Задачи:

        1)  Напишите программу, которая будет считывать файл animals.txt посимвольно с помощью функции fgetc
            и печатать всё содержимое этого файла на экран.

        2)  Та же самая задача, но название файла теперь не animals.txt, а задаётся через аргументы командной строки (argv[1]).
            У программы должен быть один аргумент командной строки - название файла для считывания.
            Если количество аргументов командной строки не равно одному (то есть если argc != 2), то нужно напечатать сообщение
            об ошибке и выйти из программы.
*/