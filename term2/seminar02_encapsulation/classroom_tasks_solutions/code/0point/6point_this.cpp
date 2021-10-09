#include <iostream>
#include <cmath>
using namespace std;

// Скрытый указатель this
// В методах каждого класса можно использовать скрытый указатель this
// Это просто указатель на данный экземпляр

struct Point {
private:
	float x, y;

public:
	// Конструктор:
	Point(float x, float y) {
		this->x = x;
		this->y = y;
	}

	// У класса может быть несколько конструкторов:
	Point() {
		x = 0;
		y = 0;
	}

	void print_this() const {
		cout << this << endl;
	}

	float get_x() const{
		return x;
	}

	float get_y() const {
		return y;
	}


	Point operator+(const Point& right) const {
		Point result = Point(x + right.x, y + right.y);
		return result;
	}

	Point& operator=(const Point& right) {
		x = right.x;
		y = right.y;
		return *this;
	}
};


ostream& operator<<(ostream& left, Point& right) {
	left << "(" << right.get_x() << ", " << right.get_y() << ")";
	return left;
}

int main() {
	Point a = Point(7, 3);

	// this это просто адрес a
	a.print_this();
	cout << &a << endl;

	/* Задание:
		1) Запустите эту программу, чтобы проверить, что this это действительно &a

		2) Напишите оператор присваивания:
			Point& operator=(const Point& right)
		   Помните, что такой оператор должен вернуть ссылку на экземпляр
	*/
}