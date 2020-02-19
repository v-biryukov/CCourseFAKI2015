#include <iostream>
#include <cmath>
using namespace std;

// Конструктор - это специальный метод класса, который вызывается при создании экземпляра
// 				 и нужным образом задаёт поля класса

// В языке C мы часто создавали функцию init (или create), которая вызывалась в при создании экземпляра
// Например при создании хеш-таблицы эта функция выделяла память и зануляла массив указателей
// В языке C++ эту роль играет контруктор

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
	Point a = Point(7.2, 3.1);  // Создаём объект, используя конструктор
	Point b(7.2, 3.1);          // Идентичный вызов
	Point c = Point();          // Используем другой конструктор
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	/* Задание:
	1) Создайте новый конструктор Point(float a)
		который приравнивает x и y к аргументу a
		Создайте экземпляр, используя этот конструктор
		
		Можно ли теперь создать новый экземпляр так и почему:
		Point p = 5;

		Можно ли теперь делать так и почему:
		p = a + 5;

	*/
}