#include <iostream>
#include <cmath>
using namespace std;

// В отличии от C, в C++ функции могут быть частью структуры
// Такие функции, называются методами,
// А структура, содержащая методы, может называться классом

struct Point {
	float x, y;

	// Обратите внимание что, так как методы структуры Point видят поля x и y,
	// то в методы не нужно передавать саму структуры, 
	// (а в operator+ не нужно передавать левый аргумент)

	float norm() const {
		return sqrtf(x*x + y*y);
	}

	void normalize() {
		float pnorm = norm();
		x /= pnorm;
		y /= pnorm;
	}


	void rotate(float theta) {
		float newx = x * cos(theta) - y * sin(theta);
		y = x * sin(theta) + y * cos(theta);
		x = newx;
	}

	Point operator+(const Point& right) const {
		Point result = {x + right.x, y + right.y};
		return result;
	}
};

// Не все функции удаётся поместить в структуру
// Функция ниже относится не к типу Point, а к типу ostream
// Сделать эту функцию методом класса ostream мы не можем, так как 
// это тип стандартной библиотеки. Поэтому эта функция остаётся обычной
ostream& operator<<(ostream& stream, const Point& p) {
	stream << "(" << p.x << ", " << p.y << ")";
	return stream;
}

int main() {
	Point a = {7.2, 3.1};
	Point b = {-4.6, 2.4};
	Point c = a + b;
	
	// Вызов методов происходит также как и доступ к полям (через точку)
	cout << "Before normalization: " << c << endl;
	c.normalize();
	cout << "After normalization: " << c << endl;


	Point d = {1, 0};
	cout << "Before rotation: " << d << endl;
	d.rotate(3.14159 / 4);
	cout << "After rotation: " << d << endl;
}