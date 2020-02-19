#include <iostream>
#include <cmath>
using namespace std;

// Конструктор копирования и оператор присваивания

struct Point
{
private:
	float x, y;

public:
	// Конструктор:
	Point(float ax, float ay)
	{
		x = ax;
		y = ay;
	}

	// У класса может быть несколько конструкторов:
	Point()
	{
		x = 0;
		y = 0;
	}

	// Конструктор копирования
	Point(const Point& p)
	{
		x = p.x;
		y = p.y;
	}

	// Оператор присваивания
	// Интересно, что это единственный оператор, который может быть определён
	//   только внутри класса
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
	/* Задание:
	1) Что вызывается в строке выше?
		Конструктор, оператор присваивания или и конструктор и оператор присваивания?
	*/

	Point b = a;
	/*
	2) Что вызывается в строке выше?
		Конструктор, оператор присваивания или и конструктор и оператор присваивания?
	*/

	Point c;
	/*
	3) Вызывается ли конструктор в строке выше?
	*/
	c = b;
	cout << a << " " << b << " " << c << endl;
	/*
		Проверьте ваши догадки в следующем файле.
	*/
}