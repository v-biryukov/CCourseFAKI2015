#include <iostream>
using namespace std;

struct Complex
{
	float re, im;
};

Complex operator+(Complex a, Complex b)
{
	Complex result = {a.re + b.re, a.im + b.im};
	return result;
}

// Перегружаем операцию  std::ostream << Complex
void operator<<(ostream& first, Complex second)
{
	first << second.re << " + " << second.im << "i";
}

int main()
{
	Complex z1 = {3, 7};
	Complex z2 = {2, -4};

	// Тут всё ок
	cout << z1 + z2;
	cout << endl;

	// Тут произойдёт ошибка. Как её исправить?
	cout << z1 << endl << z2 << endl;

	/* Задание:
		1) Исправить функцию operator<<
		2) Перегрузите операцию   std::ostream >> Complex и протестируйте её

	*/
}