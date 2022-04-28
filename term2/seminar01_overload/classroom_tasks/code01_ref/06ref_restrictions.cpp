#include <iostream>
using std::cout, std::endl;


/*
    Несмотря на то, что ссылки и указатели во многом похожи, у них есть и много больших отличий.

    Различие 5)  
        Ссылки это не совсем обычный объект, некоторые операции с ними запрещены:
        
        Ссылку нельзя сделать элементом массива

        Нельзя получить адрес ссылки (если применим & то вернётся адрес того объекта на который указывет ссылка)
        Нельзя создать укатель на ссылку
        Нельзя создать ссылку на ссылку

*/

int main() 
{

    int x = 1;
    int y = 2;
    int z = 2;

    int& a[3] = {x, y, z};  // Ошибка, создать массив из ссылок не получится

}


/*
    Задачи:

    1)  Можно ли инициализировать ссылку на int простым числом вот так:
            int& r = 5;


    2)  Ссылку на ссылку создать нельзя, но код ниже почему-то работает.
        Объясните почему этот код работает
            
            int a = 10;
            int& r1 = a;
            int& r2 = r1;

            r2 += 1;

*/