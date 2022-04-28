#include <iostream>
#include <cstdlib>
using std::cout, std::endl;

/*
	Теперь создадим конструктор, который будет выделять память 
	и заполнять его нужным образом

	Также сделаем поля приватными. В этом случае это необходимо.
	Так как если другой программист будет пользоваться нашим классом и
	поменяет поля size или data, то это может привести к серьёзным ошибкам
	и неправильной работе наших методов

	size и data будут изменяться методами класса, а не извне класса


    c_str
    Метод который возвращает C-string (строку в стиле C)
    то есть указатель на массив из char-ов
*/

class String 
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

		// Выделяем память
		data = (char*)malloc(sizeof(char) * (size + 1));

		// Копируем массив str в новый массив data
		for (int i = 0; str[i]; i++)
			data[i] = str[i];
		data[size] = '\0';
	}


	unsigned int getSize() const 
    {
		return size;
	}

	const char* c_str() const 
    {
		return data;
	}
};


ostream& operator<<(ostream& left, const String& right) 
{
	left << right.c_str();
	return left;
}


int main() {
	// Создать экземпляр, вызвав конструктор можно множеством различных способов:
	String a = String("Cat");
	String b = "Dog";
	String c("Axolotl");
	String d = {"Lion"};
	String e {"Elephant"};		
	// Предпочтительным является 5-й способ (e)   

	cout << a << endl << b << endl << c << endl << d << endl << e << endl;
}


/*  
    Задание:

	1) Создайте конструктор String(), который будет создавать пустую строку
										(size = 0, строка data содержит в себе 1 символ ('\0'))

	2) Создайте конструктор String(char a), который будет создавать строку из символа
										(size = 1, строка data содержит в себе 2 символa (a и '\0'))

	3) Создайте конструктор String(int n, char a), который будет создавать строку из n символов a
										(size = n, строка data содержит в себе n + 1 символ (n раз a и '\0'))

	Протестируйте эти конструкторы:
	String empty;
	cout << "Empty string = " << empty << endl;
	String oneletter = 'A';
	cout << "One letter string = " << oneletter << endl;

	String nletter {10, 'q'};
	cout << "N letter letter string = " << nletter << endl;
*/
