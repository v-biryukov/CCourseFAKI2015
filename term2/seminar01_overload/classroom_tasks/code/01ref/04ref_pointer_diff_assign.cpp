#include <iostream>
using std::cout, std::endl;


/*
    Несмотря на то, что ссылки и указатели во многом похожи, у них есть и много больших отличий.

    
    Различие 3)  Указатель можно переприсвоить. Если указатель сначала указывал в одно место,
        например, на переменную a, то можно просто написать
            p = &b;
        и указатель станет указывать на переменную b.

        Со ссылками такое не пройдёт, они всегда указывают на тот объект, который был указан при создании ссылки
        При попытке изменить это и написать что-то вроде
            r = b;
        ссылка автоматически разыменуется и присваивание произойдёт к тому, на что указывала ссылка
*/

int main() 
{
    int a = 10;
    int b = 20;

    int* p = &a;
    *p += 1;
    p = &b;
    *p += 1;

    cout << a << " " << b << endl;


    int& r = a;
    r += 1;
    r = b;
    r += 1;

    cout << a << " " << b << endl;
}


/*
    Задачи:

    1)  Попробуйте понять, что напечатает программа без её запуска

    2)  Запустите программу, проверьте ваши догадки и объясните результат

*/