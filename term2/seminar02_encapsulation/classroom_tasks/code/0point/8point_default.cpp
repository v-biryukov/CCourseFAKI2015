#include <iostream>
#include <cmath>
using namespace std;

/*
 Если вы не задали своих конструкторов и операторов присваивания,
 То компилятор создаст конструкторы по умолчанию за вас
 А именно он создаст:
 1) Конструктор по умолчанию (пустой):
 			Point() {};
 2) Конструктор копирования по умолчанию (просто копирует все поля):
 			Point(const Point& p)
 3) Оператор присваивания по умолчанию (просто копирует все поля):
 			Point& operator=(const Point& p)


 4) Также он создаст деструктор по умолчанию (ничего не делает):
			~Point()
	(о деструкторах позже)
*/

struct Point
{
private:
	float x, y;

public:
	float get_x()
	{
		return x;
	}

	float get_y()
	{
		return y;
	}
};


ostream& operator<<(ostream& left, Point& right)
{
	left << "(" << right.get_x() << ", " << right.get_y() << ")";
	return left;
}

int main()
{
	Point a = Point();
	Point b = a;
	Point c;
	c = a;

	cout << a << " " << b << " " << c << endl;

	/* Задание:
		1) Компилятор создаёт конструктор по умолчанию только если вы не задали свой конструктор
			Проверьте будет ли работать код выше если добавить в класс конструктор Point(float ax, float ay)
	*/
}