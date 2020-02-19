#include <iostream>
#include <cstdlib>
using namespace std;

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
	/* Задание:
		1) Выделите с помощью new и удалит с помощью delete:
			А) 1 элемент типа float
			Б) Массив из 10 элементов типа char
			В) Массив из 100 элементов типа Point
			Г) 1 элемент типа Point со значениями x = 2.2 и y = 7.1
	*/
}