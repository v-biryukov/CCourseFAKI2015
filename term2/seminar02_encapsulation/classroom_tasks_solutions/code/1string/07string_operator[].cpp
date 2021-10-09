#include <iostream>
#include <cstdlib>
using namespace std;

/*
	Напишите operator[] для строки
	Этот оператор должен работать также как и [] у массива
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

		data = (char*)malloc(sizeof(char) * (size + 1));

		// Копируем массив str в новый массив data
		for (int i = 0; str[i]; i++)
			data[i] = str[i];
		data[size] = '\0';
	}

	String() {
		cout << "Empty constructor" << endl;
		size = 0;
		data = (char*)malloc(sizeof(char) * (size + 1));
		data[0] = '\0';
	}

	unsigned int get_size() const {
		return size;
	}

	const char* c_str() const {
		return data;
	}

	~String() {
		free(data);
	}


	// Этот оператор возвращает ссылку, благодаря этому
	// мы можем изменять содержимое массива
	// То есть писать так array[i] = ...
	char& operator[](unsigned int id) {
		return data[id];
	}

	char& at(unsigned int id) {
		if (id < 0 || id > size) {
			cout << "Error! String index is out of boundary!" << endl;
			exit(1);
		}
		return data[id];
	}

};

ostream& operator<<(ostream& left, const String& right)
{
	left << right.c_str();
	return left;
}


int main() {
	String a = String("Cat");
	String b = "Dog"; 
	String c("Axolotl");

	/* Задание:
		1) Напишите перегруженный оператор взятия индекса, 
			которая должен работать также, как и [] у массива
			char& operator[](unsigned int id)


		2) Напишите функцию at, которая работает аналогично operator[], но при этом
			проверяет, находится ли индекс в допустимых пределах
			Если не находится, то она должна печатать ошибку и выходить из программы
	*/

	cout << c << endl;
	c[1] = 't';
	cout << c << endl;
	c.at(10) = 'b';
	cout << c << endl;
}