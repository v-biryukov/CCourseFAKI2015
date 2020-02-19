#include <iostream>
#include <cmath>
using namespace std;

// Скрытый указатель this
// В методах каждого класса можно использовать скрытый указатель this
// Это просто указатель на данный экземпляр

struct Point
{
private:
	float x, y;

public:
	// Конструктор:
	Point(float ax, float ay)
	{
		this->x = ax;
		this->y = ay;
	}

	// У класса может быть несколько конструкторов:
	Point()
	{
		x = 0;
		y = 0;
	}

	void print_this()
	{
		cout << this << endl;
	}

	float get_x()
	{
		return x;
	}

	float get_y()
	{
		return y;
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

	// this это просто адрес a
	a.print_this();
	cout << &a << endl;

	// Запустите эту программу, чтобы проверить, что this это действительно &a

}