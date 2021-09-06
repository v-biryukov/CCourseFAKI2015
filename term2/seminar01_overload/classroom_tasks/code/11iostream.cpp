#include <iostream>


int main() {
	int a = 123;
	float b = 4.87;
	char str[] = "Hello";


	std::cout << a;
	std::cout << "\n";
	std::cout << b;
	std::cout << "\n";
	std::cout << str;
	std::cout << "\n";

	std::cout << a << "\n" << b << "\n" << str << "\n";

	using namespace std; // Начиная с этого момента можно не писать std::
	cout << a << "\n" << b << "\n" << str << "\n";

	// Вместо "\n" можно использовать специальный объект std::endl
	cout << a << endl << b << endl << str << endl;


	// Для считывания используют специальный объект std::cin из стандартной библиотеки
	cin >> a;
	cout << "Read variable a from console. a = " << a << endl;
}