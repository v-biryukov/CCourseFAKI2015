#include <iostream>
using std::cout, std::endl;


/*
    Несмотря на то, что ссылки и указатели во многом похожи, у них есть и много больших отличий.
    (помимо разной инициализации и того, что ссылку не нужно постоянно разыменовывать)

    Различие 4)  
        Арифметика указателей. 
        К указателю можно прибавлять/отнимать целые числа. Можно вычесть 2 указателя.
        Можно применить [] к указателю. При всём этом, желательно, чтобы указатель указывал на элемент массива.
        Неаккуратное использование арифметики указателей может привести к ошибкам.
        Например, можно прибавить к указателю не то число и выйти за пределы массива.
        

        Ничего такого со ссылками сделать нельзя.
        При попытке прибавить к ссылке число, оно прибавится к той переменной, на которую указывает ссылка.
        Так как ссылка автоматически разыменуется.

*/

int main() 
{
    int a[5] = {10, 20, 30, 40, 50};
    
    int* p = &a[0];

    p += 1;     // Увеличиваем указатель
    *p += 1;    // Увеличиваем то, на что указывает указатель


    int& r = a[0];

    r += 1;     // Увеличиваем то, на что указывает ссылка (она автоматически разыменовывается)
}


/*
    Задачи:

    1)  Чему будет равен массив a в конце данной программы

*/