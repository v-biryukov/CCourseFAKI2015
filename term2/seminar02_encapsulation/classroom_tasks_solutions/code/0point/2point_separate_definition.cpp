#include <iostream>
#include <cmath>
using namespace std;

// Методы могут быть объявлены внутри класса
struct Point {
	float x, y;

	float norm();
	void normalize();

	Point operator+(const Point& right);
};

// А описаны вне класса
// Только к названию класса нужно добавить Point:: (также как и у пространства имён)
float Point::norm() {
	return sqrtf(x*x + y*y);
}

void Point::normalize() {
	float pnorm = norm();
	x /= pnorm;
	y /= pnorm;
}

Point Point::operator+(const Point& right) {
	Point result = {x + right.x, y + right.y};
	return result;
}

// operator<< это не метод, а просто функция
ostream& operator<<(ostream& left, const Point& right) {
	left << "(" << right.x << ", " << right.y << ")";
	return left;
}

int main() {
	Point a = {7.2, 3.1};
	Point b = {-4.6, 2.4};
	Point c = a + b;
	
	cout << c << endl;
	// Вызов методов происходит также как и лоступ к полям (через точку)
	c.normalize();
	cout << c << endl;
}