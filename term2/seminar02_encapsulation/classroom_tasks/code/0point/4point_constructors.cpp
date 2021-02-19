#include <iostream>
#include <cmath>
using namespace std;

// Конструктор - это специальный метод класса, который вызывается при создании экземпляра
// 				 и нужным образом задаёт поля класса

// В языке C мы часто создавали функцию init (или create), которая вызывалась в при создании экземпляра
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

	float get_x() const
	{
		return x;
	}

	float get_y() const
	{
		return y;
	}

	float norm() const
	{
		return sqrtf(x*x + y*y);
	}

	void normalize()
	{
		float pnorm = norm();
		x /= pnorm;
		y /= pnorm;
	}

	Point operator+(const Point& right) const
	{
		Point result = Point(x + right.x, y + right.y);
		return result;
	}
};

ostream& operator<<(ostream& left, Point& right)
{
	left << "(" << right.get_x() << ", " << right.get_y() << ")";
	return left;
}

int main()
{
	Point a1 = Point(7, 3);  // Создаём объект, используя конструктор Point(float ax, float ay)
	Point a2(7, 3);          // Идентичный вызов конструктора
	Point a3 {7, 3};         // Идентичный вызов конструктора

	Point b1 = Point();      // Используем другой конструктор Point()
	Point b2;				 // Идентичный вызов конструктора
	Point b3 {};			 // Идентичный вызов конструктора
	

	cout << "a0 = " << a0 << endl;
	cout << "a1 = " << a1 << endl;
	cout << "a2 = " << a2 << endl;
	cout << "a3 = " << a3 << endl;

	cout << "b1 = " << b1 << endl;
	cout << "b2 = " << b2 << endl;
	cout << "b3 = " << b3 << endl;

	/* Задание:
	1) Создайте новый конструктор Point(float a)
		который приравнивает x и y к числу a
		Создайте экземпляр, используя этот конструктор тремя разными способами
		
		Можно ли теперь создать новый экземпляр так и почему:
		Point с = 5;

	2) Создайте новый конструктор Point(const Point& p) (конструктор копирования)
		который приравнивает x и y к полям структуры p
		Создайте экземпляр, используя этот конструктор тремя разными способами

		Можно ли теперь создать новый экземпляр так и почему:
		Point с = a1;
	*/
}