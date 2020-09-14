#include <stdio.h>

/*

Динамическое программирование в теории управления и теории вычислительных систем — 
способ решения сложных задач путём разбиения их на более простые подзадачи

Слово «программирование» в словосочетании «динамическое программирование» 
в действительности к «традиционному» программированию (написанию кода) почти никакого отношения 
не имеет и имеет смысл как в словосочетании «математическое программирование», 
которое является синонимом слова «оптимизация». 

*/


int main()
{


    /*  1) Черепашка:
    В левом верхнем углу прямоугольной таблицы размером N*M находится черепашка. 
    В каждой клетке таблицы записано некоторое число. 
    Черепашка может перемещаться ТОЛЬКО вправо или вниз, при этом маршрут 
    черепашки заканчивается в правом нижнем углу таблицы.
    
    Подсчитаем сумму чисел, записанных в клетках, через которую проползла черепашка (включая начальную и конечную клетку). 
    Найдите наибольшее возможное значение этой суммы.
    
    
    1 1 2 1 
    2 2 1 1 
    2 1 2 1
    В этом случае черепашке нужно двигаться вниз, а потом направо
    Ответ - 9
    
    
    5  5  1  1  1  1  1  1 
    1  5  1  1 20 20  1  1 
    1  5  1  1  1  1  1  1
    1  5  5  5  5  1  1  1 
    1  1  1  1  5  5  1  1 
    1  1  1  1  1  5  5  5
    Если двигаться только по пятёркам то сумма будет - 65
    Если захватить 20-ки, то сумма будет 79
    Ответ - 79
    
    
    На вход подайтся N, M и элементы массива
    Вам нужно написать масимально возможную сумму
    
    Подсказка: Пусть C(i,j) -- наибольшее возможное значение суммы, если черепашка доползла до точки (i, j). 
    Как C(i, j) зависит от C(i-1, j) и C(i, j-1)?
    */

}