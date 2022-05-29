#include <iostream>
#include <cmath>
using std::cout, std::endl;


void inc(int& x)
{
    x += 1;
}

void normalize(float& x, float& y)
{
    float norm = std::sqrt(x * x + y * y);
    x /= norm;
    y /= norm;
}


int main() 
{
    int a = 5;
    inc(a);
    cout << a << endl;

    float x = 9, y = 6;
    normalize(x, y);
    cout << x << " " << y << endl;
}


/*
    Задачи:
    
    1)  Напишите функцию void inc(int& x), которая должна принимать объект типа int
        и увеличивать его на 1
        Вызовите эту функцию из main и протестируйте её работу

    2)  Напишите функцию void normalize(float& x, float& y), которая должна принимать 
        2 объекта типа float и нормализировать их. То есть делить их на некоторое число,
        так чтобы было x*x + y*y == 1
        
        Для этого x и y нужно разделить на sqrt(x*x + y*y)


    3)  Можно ли передать в функцию sqr не переменную, а число?
        То есть, можно ли написать так: 
            sqr(5)
 

*/