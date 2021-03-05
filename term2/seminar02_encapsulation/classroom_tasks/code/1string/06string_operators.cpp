#include <iostream>
#include <cstdlib>
using namespace std;

/*
	
*/

struct String
{
private:
	unsigned int size;
	char* data;

public:

	String(const char* str)
	{
		// Находим размер строки str (strlen не будем пользоваться)
		size = 0;
		while (str[size])
			size++;

		data = new char[size + 1];

		// Копируем массив str в новый массив data
		for (int i = 0; str[i]; i++)
			data[i] = str[i];
		data[size] = '\0';
	}

	String()
	{
		size = 0;
		data = new char;
		data[0] = '\0';
	}

	unsigned int get_size() const
	{
		return size;
	}

	const char* c_str() const
	{
		return data;
	}

	~String()
	{
		delete [] data;
	}

};

ostream& operator<<(ostream& left, const String& right)
{
	left << right.c_str();
	return left;
}


int main()
{
	String a = String("Cat");
	String b = "Dog"; 
	String c("Axolotl");


	/* Задание:
		Напишите следующие перегруженные методы для строки:
		1) Оператор сложения
			String operator+(const String& right) const
			Который будет складывать 2 строки.
			При этом будет создаваться новая строка, которая и будет возвращаться
		2) Оператор присваивания сложения
			String& operator+=(const String& right)
			Который будет прибавлять к левой строке правую
			При этом новая строка не должна создаваться
			Этот оператор должен возвращать ссылку на левый операнд
		3) Оператор присваивания
			String& operator=(const String& right)
			Который будет приравнивать левый операнд к правому
			При этом новая строка не должна создаваться
			Этот оператор должен возвращать ссылку на левый операнд
			Также в этом операторе нужно рассмотреть частный случай
			когда левый и правый операнды это один и тот же объект
		4) Оператор сравнения
			bool operator==(const String& right) const
			Который проверяет строки на равенство и возвращает
			true или false

	String a = "Cat";
	String b = "Dog"; 
	String c = "Axolotl";
	String d = "Cat";

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	String x = a + b;
	cout << "x = a + b; x = " << x << endl;

	x += c;
	cout << "x += c; x = " << x << endl;

	cout << "d == a: " << d == a << endl;
	cout << "c == a: " << c == a << endl;




}