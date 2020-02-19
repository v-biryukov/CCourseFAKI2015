#include <iostream>
#include <cmath>
using namespace std;

// В отличии от C, в C++ функции могут быть частью структуры
// Такие функции, называются методами,
// А структура, содержащая методы, может называться классом

struct Point
{
	float x, y;

	// Методы могут быть объявлены внутри класса

	float norm();
	float normalize();

	Point operator+(const Point& right);
	Point operator*(float right);
};

// а описаны вне класса
// Только к названию класса нужно добавить Point:: (также как и у пространства имён)

float Point::norm()
{
	return sqrtf(x*x + y*y);
}

float Point::normalize()
{
	float pnorm = norm();
	x /= pnorm;
	y /= pnorm;
}

Point Point::operator+(const Point& right)
{
	Point result = {x + right.x, y + right.y};
	return result;
}

Point Point::operator*(float right)
{
	Point result = {x * right, y * right};
	return result;
}

// Не все функции удаётся поместить в структуру
// float не является структурой, поэтому методы мы туда добавить не можем
// Хоть ostream и является структурой, но она определена в библиотеке и
// менять её нельзя

Point operator*(float left, const Point& right)
{
	Point result = {left * right.x, left * right.y};
	return result;
}

ostream& operator<<(ostream& left, const Point& right)
{
	left << "(" << right.x << ", " << right.y << ")";
	return left;
}

int main()
{
	Point a = {7.2, 3.1};
	Point b = {-4.6, 2.4};
	Point c = a * 5 + 2 * b;
	
	cout << c << endl;
	// Вызов методов происходит также как и лоступ к полям (через точку)
	c.normalize();
	cout << c << endl;

	/* Задание:
	1) Добавьте метод rotate из предыдущей задачи

	2) Добавьте метод operator+= из предыдущей задачи
	*/
}