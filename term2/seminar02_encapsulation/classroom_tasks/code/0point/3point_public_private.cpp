#include <iostream>
#include <cmath>
using namespace std;

// Модификаторы доступа private и public:
//    private - эти поля и методы могут использовать только методы этого класса
//    public - эти поля и методы могут использоваться где угодно

// При использовании ключевого слова struct - по умолчанию используется public
// При использовании ключевого слова class  - по умолчанию используется private

// Они нужны, чтобы скрыть от программистов, которые будут использовать этот класс
//             детали реализации и запретить использовать его 'неправильным' способом

class Point
{
private:
	float x, y;

public:

	float get_x()
	{
		return x;
	}

	float get_y()
	{
		return y;
	}

	void set_x(float ax)
	{
		x = ax;
	}

	void set_y(float ay)
	{
		y = ay;
	}

	float norm()
	{
		return sqrtf(x*x + y*y);
	}

	float normalize()
	{
		float pnorm = norm();
		x /= pnorm;
		y /= pnorm;
	}

	Point operator+(const Point& right)
	{
		Point result;
		result.x = x + right.x;
		result.y = y + right.y;
		return result;
	}

	Point operator*(float right)
	{
		Point result;
		result.x = x * right;
		result.y = y * right;
		return result;
	}
};

// Обратите внимание, что эти функций теперь не могут использовать поля x и у
// Приходится использовать неудобные set_x и get_x

Point operator*(float left, Point& right)
{
	Point result;
	result.set_x(left * right.get_x());
	result.set_y(left * right.get_y());
	return result;
}

ostream& operator<<(ostream& left, Point& right)
{
	left << "(" << right.get_x() << ", " << right.get_y() << ")";
	return left;
}

int main()
{
	// Теперь у нас не получится так просто иницилизировать значения:
	// Так как x и y - приватные
	// Point a = {7.2, 3.1};

	Point b;
	b.set_x(0.4);
	b.set_y(0.7);
	
	
	// Хотим напечатать x-компоненту точки b, но будет ошибка (потому что x - это private)
	//cout << b.x << endl;

	/* Задание:
		1) Исправьте ошибку выше
		2) Написать приватный метод void clampx(), который
			будет проверять находится ли переменная x в диапазоне [0, 1]
			если же x < 0, то эта функция должна устанавливать x = 0
			если же x > 1, то эта функция должна устанавливать x = 1

			Написать аналогичный приватный метод clampy()
		3) Вызвать эти методы в конце функций set_x, set_y, operator+, operator*
			Протестировать это в функции main:
			Point a;
			a.set_x(123);
			a.set_y(-123);
			Point c = 0.5 * a + 3.2 * b;
			cout << a << " " << c << endl; 
			
			Теперь x и y никогда не выйдут за пределы [0, 1]
	*/
}