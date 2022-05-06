#include <iostream>
using std::cout, std::endl;


/*
    Несмотря на то, что ссылки и указатели во многом похожи, у них есть и много больших отличий.
    (помимо разной инициализации и того, что ссылку не нужно постоянно разыменовывать)


    Различие 1)  
        Указатель можно создать без инициализации вот так:
            int* p;
        В этом случае в p будет храниться произвольный адрес.
        Разыменовывать такой указатель, не задав его значение адресом какого-либо объекта,
        очень опасно, это может привести к сложновыявляемым ошибкам.

        Ссылку нельзя создать без инициализации, то есть так нельзя:
            int& r;
        При создании ссылки нужно указать на что она будет указывать


    Различие 2)  
        Указатель можно приравнять нулевому значению
        В C++ вводится специальное нулевое значение для указателя nullptr
        Вместо NULL, который был просто равен числу 0. В C++ лучше использовать nullptr
        Разыменование нулевого указателя также приведёт к ошибке.

        Ссылку нельзя присвоить никакому нулевому значению

*/

int main() 
{

}


/*
    Задачи:

    1)  Попробуйте создать:
        a)  Указатель без инициализации
        б)  Ссылку без инициализации

        в)  Указатель, равнуй нулевому значению nullptr
        г)  Ссылку, равную нулю
    
        Скомпилируется ли программа в этих 4-х случаях?
*/