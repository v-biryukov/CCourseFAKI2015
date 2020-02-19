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
		cout << "Constructor(float, float)" << endl;
		x = ax;
		y = ay;
	}

	// У класса может быть несколько конструкторов:
	Point()
	{
		cout << "Empty Constructor()" << endl;
		x = 0;
		y = 0;
	}

	// Конструктор копирования
	Point(const Point& p)
	{
		cout << "Copy Constructor(Point)" << endl;
		x = p.x;
		y = p.y;
	}

	// Оператор присваивания
	// Интересно, что это единственный оператор, который может быть определён
	//   только внутри класса
	Point& operator=(const Point& p)
	{
		cout << "Assign operator" << endl;
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
	cout << "Part 1" << endl;
	Point a = Point(7.2, 3.1);
	/* Задание:
	1) Что вызывается в строке выше?
		Конструктор, оператор присваивания или и конструктор и оператор присваивания?
	*/

	cout << "Part 2" << endl;
	Point b = a;
	/*
	2) Что вызывается в строке выше?
		Конструктор, оператор присваивания или и конструктор и оператор присваивания?
	*/

	cout << "Part 3" << endl;
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