#include <iostream>
#include <cmath>
using namespace std;

// Константными могут быть не только аргументы функции, но и методы
// Метод - константный, если он не изменяет значения полей

// Например, norm - константный метод, потому что он не изменяет x и y
// Пишется так: float norm() const

// Следует использовать const везде, где это возможно

struct Point
{
private:
	float x, y;

public:

	Point(float ax, float ay)
	{
		x = ax;
		y = ay;
	}

	Point()
	{
		x = 0;
		y = 0;
	}

	Point(const Point& p)
	{
		x = p.x;
		y = p.y;
	}

	Point& operator=(const Point& p)
	{
		x = p.x;
		y = p.y;
		return *this;
	}

	float get_x()
	{
		return x;
	}

	float get_y()
	{
		return y;
	}

	float norm() const
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
		Point result = Point(x + right.x, y + right.y);
		return result;
	}

	Point operator*(float right)
	{
		Point result = Point(x * right, y * right);
		return result;
	}
};


Point operator*(float left, Point& right)
{
	Point result = Point(left * right.get_x(), left * right.get_y());
	return result;
}

ostream& operator<<(ostream& left, Point& right)
{
	left << "(" << right.get_x() << ", " << right.get_y() << ")";
	return left;
}

int main()
{
	Point a = Point(7.2, 3.1);
	Point b = 4.6 * a;
	cout << a << endl;
	cout << b << endl;

	/* Задание:
		1) В функции operator*(float left, Point& right) и operator<<(ostream& left, Point& right)
			right передаётся не по константе, хотя он внутри изменяется.
			Исправьте это

			(Подсказка: Возможно const потребуется поставить в нескольких местах)
	*/
}