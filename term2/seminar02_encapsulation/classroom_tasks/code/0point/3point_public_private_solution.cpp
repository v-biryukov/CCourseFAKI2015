#include <iostream>
#include <cmath>
using namespace std;

// Модификаторы доступа private и public:
//    private - эти поля и методы могут использовать только методы этого класса и друзья
//    public - эти поля и методы могут использоваться где угодно

// При использовании ключевого слова struct - по умолчанию используется public
// При использовании ключевого слова class  - по умолчанию используется private

// Они нужны, чтобы скрыть от программистов, которые будут использовать этот класс
// детали реализации и запретить использовать его 'неправильным' способом

// Сделаем поля x и y приватными
// Теперь до них можно будет доступиться только в методах класса Point и в друзьях
// Чтобы можно было работать с этими полями вне класса напишем методы
// get_x, get_y, set_x, set_y (так называемые геттеры и сеттеры)

class Point
{
private:
	float x, y;

	void clampx()
	{
		if (x > 1)
			x = 1;
		else if (x < 0)
			x = 0;
	}

	void clampy()
	{
		if (y > 1)
			y = 1;
		else if (y < 0)
			y = 0;
	}

public:

	float get_x() const
	{
		return x;
	}

	float get_y() const
	{
		return y;
	}

	void set_x(float ax)
	{
		x = ax;
		clampx();
	}

	void set_y(float ay)
	{
		y = ay;
		clampy();
	}

	float norm() const
	{
		return sqrtf(x*x + y*y);
	}

	void normalize()
	{
		float pnorm = norm();
		x /= pnorm;
		y /= pnorm;
	}

	Point operator+(const Point& right) const
	{
		Point result;
		result.x = x + right.x;
		result.y = y + right.y;
		result.clampx();
		result.clampy();
		return result;
	}
};

// Обратите внимание, что обычные функций теперь не могут использовать поля x и у
// Приходится использовать неудобные get_x и get_y
// Другой вариант -- можно было сделать эту функцию другом нашего класса
ostream& operator<<(ostream& left, Point& right)
{
	left << "(" << right.get_x() << ", " << right.get_y() << ")";
	return left;
}

int main()
{
	// Теперь у нас не получится так просто иницилизировать значения:
	// Так как x и y - приватные
	// Point a = {7, 3}; <-- это ошибка

	Point b;
	b.set_x(0.4);
	b.set_y(0.7);
	
	
	// Хотим напечатать x-компоненту точки b, но будет ошибка (потому что x - это private)
	cout << b.get_x() << endl;
	// Как исправить эту ошибку?

	/* Задание:
		Предположим, что мы хотим создать не обычную точку,
		а точку, которая всегда находится в квадрате [0, 1] x [0, 1]
		Для этого нужно сделать следующее:

		1) Написать приватный метод void clampx(), который
			будет проверять находится ли переменная x в диапазоне [0, 1]
			если же x < 0, то эта функция должна устанавливать x = 0
			если же x > 1, то эта функция должна устанавливать x = 1

			Написать аналогичный приватный метод clampy()

		2) Вызвать эти методы в конце функций set_x, set_y, operator+
			Протестировать это в функции main:
			Point a;
			a.set_x(123);
			a.set_y(-123);
			Point c = a + b;
			cout << a << " " << c << endl; 
			
			Теперь x и y никогда не выйдут за пределы [0, 1]
	*/

	cout << "Testing clamp" << endl;
	Point a;
	a.set_x(123);
	a.set_y(-123);
	cout << "a = " << a << endl; 
	Point c = a + b;
	cout << "a = " << a << "; b = " << b <<"; c = a + b = " << c << endl; 
}