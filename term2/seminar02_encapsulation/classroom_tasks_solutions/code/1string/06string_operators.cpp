#include <iostream>
#include <cstdlib>
using namespace std;

/*
	
*/

struct String {
private:
	unsigned int size;
	char* data;

public:

	String(const char* str) {
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

	String() {
		size = 0;
		data = new char;
		data[0] = '\0';
	}

	String(const String& s) {
		size = s.size;
		data = new char[size + 1];
		for (int i = 0; i < size; ++i) {
			data[i] = s.data[i];
		}
		data[size] = '\0';
	}

	String(int n, char a) {
		size = n;
		data = (char*)malloc(sizeof(char) * (n + 1));
		for (int i = 0; i < n; ++i) {
			data[i] = a;
		}
		data[n] = '\0';
	}


	String operator+(const String& right) {
		// Создаём новую строку нужного размера и заполняем её нужными значениями
		String result(size + right.get_size(), '\0');
		for (int i = 0; i < size; ++i) {
			result.data[i] = data[i];
		}

		for (int i = 0; i < right.size; ++i) {
			result.data[size + i] = right.data[i];
		}
		result.data[result.size] = '\0';
		return result;
	}

	String& operator+=(const String& right) {
		if (right.size == 0) {
			return *this;
		}
		// Находим новый размер
		unsigned int sum_size = size + right.get_size();
		
		// Наша строка устроена так, что всегда нужно перевыделять память
		// Выделяем память под суммарную строку и задаём её значением из строк слагаемых
		char* sum_data = new char[sum_size + 1];
		for (unsigned i = 0; i < size; i++) {
			sum_data[i] = data[i];
		}
		for (unsigned i = size; i < sum_size; i++) {
			sum_data[i] = right.data[i - size];
		}
		sum_data[sum_size] = '\0';


		// Удаляем старую строку
		delete [] data;
		// Задаём значения полей
		data = sum_data;
		size = sum_size;
		// Возвращаем текущий экземпляр (Помните, что operator+= всегда возвращает ссылку на левый аргумент)
		return *this;
	}

	/*  Замечание:
		Операторы + и += обычно не нужно реализовывать вместе, так как
		можно получить один из другого (если есть оператор присваивания)

		String operator+(const String& right) {
			String result = *this;
			result += right;
			return result;
		}

		String& operator+=(const String& right) {
			*this = *this + right;
			return *this;
		}
	*/


	String& operator=(const String& right) {
		// Проверяем случай присваивания строки с самой собой  (a = a)
		// Помните, что this - это указатель на экземпляр данного класса
		// &right - это адрес правой строки, this - адрес левой
		if (&right == this) {
			return *this;
		}

		// Выделяем память под данные для новой строки и задаём их
		unsigned int new_size = right.get_size();
		char* new_data = (char*)malloc(sizeof(char) * (new_size + 1));
		for (unsigned i = 0; i < new_size; i++)
			new_data[i] = right.data[i];
		new_data[new_size] = '\0';
		
		// Удаляем старые данные и приравниваем data к новым данным
		free(data);
		data = new_data;
		size = new_size;

		// Возвращаем текущий экземпляр (Помните, что operator= всегда возвращает ссылку на левый аргумент)
		return *this;
	}



	bool operator==(const String& right) const {
		if (size != right.size) {
			return false;
		}

		for (unsigned i = 0; i < size; i++) {
			if (data[i] != right.data[i])
				return false;
		}
		return true;
	}

	unsigned int get_size() const {
		return size;
	}

	const char* c_str() const {
		return data;
	}

	~String() {
		delete [] data;
	}

};

ostream& operator<<(ostream& left, const String& right) {
	left << right.c_str();
	return left;
}


int main() {
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
			Этот оператор должен возвращать ссылку на левый операнд, то есть *this
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

	cout << "d == a: " << (d == a) << endl;
	cout << "c == a: " << (c == a) << endl;
	*/

	String a {"Cat"};
	String b {"Dog"}; 
	String c {"Axolotl"};
	String d {"Cat"};

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	String x = a + b;
	cout << "x = a + b; x = " << x << endl;

	x += c;
	cout << "x += c; x = " << x << endl;

	cout << "d == a: " << (d == a) << endl;
	cout << "c == a: " << (c == a) << endl;

}