#include <iostream>
#include <cmath>
using namespace std;

// В данном файле представлена структура Point - описывающая точку в двух измерениях
// И функции для работы с ней

struct Point
{
	float x, y;
};

float norm(const Point& p)
{
	return sqrtf(p.x*p.x + p.y*p.y);
}

float normalize(Point& p)
{
	float pnorm = norm(p);
	p.x /= pnorm;
	p.y /= pnorm;
}

Point operator+(const Point& left, const Point& right)
{
	Point result = {left.x + right.x, left.y + right.y};
	return result;
}

Point operator*(const Point& left, float right)
{
	Point result = {left.x * right, left.y * right};
	return result;
}

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
	normalize(c);
	cout << c << endl;

	/* Задание:
		1) Напишите функцию void rotate(Point& p, float theta),
		   которая будет поворачивать точку относительно начала координат на угол theta
		   по формулам:
		   		x' = x * cos(theta) - y * sin(theta)
		   		y' = x * sin(theta) + y * cos(theta)

		   	Проверьте работу функции повернув точку {1, 0} на угол (3.14159 / 4)
		   	Должно получиться {0.707, 0.707}
	
		2) Напишите функцию Point& operator+=(Point& left, const Point& right)
			Проверьте работу этой функции
	*/
}