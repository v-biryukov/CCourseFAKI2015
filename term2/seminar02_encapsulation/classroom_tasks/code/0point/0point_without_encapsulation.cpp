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

void normalize(Point& p)
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

ostream& operator<<(ostream& stream, const Point& p)
{
	stream << "(" << p.x << ", " << p.y << ")";
	return stream;
}

int main()
{
	Point a = {7.2, 3.1};
	Point b = {-4.6, 2.4};
	Point c = a + b;
	
	cout << "Before normalization: " << c << endl;
	normalize(c);
	cout << "After normalization: " << c << endl;

	/*
	Задание:
		1) Напишите функцию void rotate(Point& p, float theta),
		   которая будет поворачивать точку относительно начала координат 
		   на угол theta по формулам:
		   		x' = x * cos(theta) - y * sin(theta)
		   		y' = x * sin(theta) + y * cos(theta)

		   Проверьте работу функции повернув точку {1, 0} на угол (3.14159 / 4)
		   Должно получиться примерно {0.707, 0.707}
		
		2) Сделайте функции norm, normalize, operator+ и rotate
		   методами класса Point
		   (решение в следующей части)
	*/
}