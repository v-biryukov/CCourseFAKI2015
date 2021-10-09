#include <iostream>
#include <string>
using namespace std;


// Простой класс с перегруженным дружественным оператором  ostream << Point
class Point {
	int x, y;

public:

	friend ostream& operator<<(ostream& left, const Point& right);
};

ostream& operator<<(ostream& left, const Point& right) {
	left << "(" << right.x << ", " << right.y << ")";
	return left;
}



/* Инициализация по значению
   T a {};
*/

int main() {
	// Переменные основных типов по умолчанию не инициализируются
	int x {};
	cout << x << endl;

	// Массивы по умолчанию не инициализируются
	int arr[10] {};
	for (int i = 0; i < 10; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	// Для классов вызывается конструктор по умолчанию
	// В этом примере создастся пустая строка ""
	string s;
	cout << s << endl;

	// Если у класса нет конструктора по умолчанию, то компилятор сам
	// сгенерирует его: Point() {}
	// Этот конструктор не будет ничего делать. В том числе не будет ничего инициализировать.
	Point p;
	cout << p << endl;
}