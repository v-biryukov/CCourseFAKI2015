/*
    Друзья

    
    Бывает ситуации, когда мы хотим доступиться к приватным полям класса из других функций или классов.
    А создавать геттеры/сеттеры, для того чтобы предоставить этот доступ мы не хотим или не можем.

    Тогда мы можем сделать другие классы и/или функции дружественными нашему классу.
    Такие дружественные классы и/или функции могут иметь доступ к приватным полям нашего класса.
    Чтобы это сделать, нужно внутри нашего класса написать ключевое слово friend и объявление функции 
    и/или класса, который вы хотите сделать дружественным.

    В данном примере функция operator<<(std::ostream& out, const RestrictedPoint& a) является
    дружественной функцией нашего класса. Именно поэтому внутри этой функции мы можем использовать приватные
    поля mx и my.
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using std::cout, std::endl;



class RestrictedPoint 
{
private:

    float mx, my;

public:

    RestrictedPoint(float x, float y)
    {
        mx = std::clamp(x, 0.0f, 1.0f);
        my = std::clamp(y, 0.0f, 1.0f);
    }

    RestrictedPoint operator+(const RestrictedPoint& right) const 
    {
        RestrictedPoint result(std::clamp(mx + right.mx, 0.0f, 1.0f),
                               std::clamp(my + right.my, 0.0f, 1.0f));
        return result;
    }

    friend std::ostream& operator<<(std::ostream& out, const RestrictedPoint& a);
};


std::ostream& operator<<(std::ostream& out, const RestrictedPoint& a) 
{
    out << "(" << a.mx << ", " << a.my << ")";
    return out;
}


int main() 
{
    RestrictedPoint a = RestrictedPoint(0.5, 1.2);
    cout << a << endl;
}



/*
    Задача:

        Закомментируйте строку 

            friend std::ostream& operator<<(std::ostream& out, const RestrictedPoint& a);

        в классе и убедитесь, что после этого программа будет выдавать ошибку, так как теперь эта 
        функция не сможет доступиться до приватных полей mx и my.
*/