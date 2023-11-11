#include <iostream>
#include <cmath>
#include "point.h"

Point::Point() : mx(0.0f), my(0.0f)
{
}

Point::Point(float x, float y) : mx(x), my(y)
{
}

float Point::getX() const 
{
	return mx;
}

float Point::getY() const 
{
	return my;
}

void Point::setX(float x) 
{
	mx = x;
}

void Point::setY(float y) 
{
	my = y;
}

float Point::norm() const 
{
	return std::sqrt(mx * mx + my * my);
}

void Point::normalize() 
{
	float pnorm = norm();
	mx /= pnorm;
	my /= pnorm;
}

float Point::distance(Point p) const 
{
	return std::sqrt((p.mx - mx) * (p.mx - mx) + (p.my - my) * (p.my - my));
}

Point Point::operator+(Point right) const 
{
	Point result = {mx + right.mx, my + right.my};
	return result;
}

Point Point::operator*(float a) const 
{
	Point result = {a * mx, a * my};
	return result;
}

Point operator*(float a, Point p) 
{
	Point result = {a * p.mx, a * p.my};
	return result;
}

std::ostream& operator<<(std::ostream& left, Point right) 
{
	left << "(" << right.mx << ", " << right.my << ")";
	return left;
}