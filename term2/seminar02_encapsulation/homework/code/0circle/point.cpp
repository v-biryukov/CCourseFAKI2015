#include <iostream>
#include <cmath>

#include "point.h"

using namespace std;

// Конструкторы
// Инициализация экземпляра производится с помощью
// списка инициализации
Point::Point(float ax, float ay) : x(ax), y(ay) 
{
}
Point::Point() : x(0), y(0) 
{
}

// Обычные методы класса Point:
float Point::get_x() const
{
	return x;
}
float Point::get_y() const
{
	return y;
}
void Point::set_x(float x)
{
	this->x = x;
}
void Point::set_y(float y)
{
	this->y = y;
}

float Point::norm() const
{
	return sqrtf(x*x + y*y);
}

void Point::normalize()
{
	float pnorm = norm();
	x /= pnorm;
	y /= pnorm;
}

float Point::distance(const Point& p) const
{
	return sqrtf((p.x - x)*(p.x - x) + (p.y - y)*(p.y - y));
}

Point Point::operator+(const Point& right) const
{
	Point result = {x + right.x, y + right.y};
	return result;
}

Point Point::operator*(float a) const
{
	Point result = {a * x, a * y};
	return result;
}



// Дружественные функции класса Point
Point operator*(float a, const Point& p)
{
	Point result = {a * p.x, a * p.y};
	return result;
}

ostream& operator<<(ostream& left, const Point& right)
{
	left << "(" << right.x << ", " << right.y << ")";
	return left;
}