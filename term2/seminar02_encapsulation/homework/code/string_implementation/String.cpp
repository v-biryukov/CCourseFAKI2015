#include <iostream>
#include <cstdlib>
#include "String.h"

String::String() {
	size = 0;
	data = new char[1];
	data[0] = '\0';
}

String::String(char a) {
	size = 1;
	data = new char[2];
	data[0] = a;
	data[1] = '\0';
}
String::String(const char* str) {
	// Находим размер строки str (strlen не будем пользоваться)
	size = 0;
	while (str[size]) {
		size++;
	}

	data = new char[size + 1];
	// Копируем массив str в новый массив data
	for (size_t i = 0; str[i]; i++)
		data[i] = str[i];
	data[size] = '\0';
}



String::String(const String& s) {
	size = s.size;
	data = new char[size + 1];
	for (size_t i = 0; i < size; ++i) {
		data[i] = s.data[i];
	}
	data[size] = '\0';
}

String::String(size_t n, char a) {
	size = n;
	data = (char*)malloc(sizeof(char) * (n + 1));
	for (size_t i = 0; i < n; ++i) {
		data[i] = a;
	}
	data[n] = '\0';
}

String& String::operator=(const String& right) {
	// Проверяем случай присваивания строки с самой собой  (a = a)
	// Помните, что this - это указатель на экземпляр данного класса
	// &right - это адрес правой строки, this - адрес левой
	if (&right == this) {
		return *this;
	}

	// Выделяем память под данные для новой строки и задаём их
	size_t new_size = right.get_size();
	char* new_data = (char*)malloc(sizeof(char) * (new_size + 1));
	for (size_t i = 0; i < new_size; i++)
		new_data[i] = right.data[i];
	new_data[new_size] = '\0';
	
	// Удаляем старые данные и приравниваем data к новым данным
	free(data);
	data = new_data;
	size = new_size;

	// Возвращаем текущий экземпляр (Помните, что operator= всегда возвращает ссылку на левый аргумент)
	return *this;
}


String String::operator+(const String& right) {
	// Создаём новую строку нужного размера и заполняем её нужными значениями
	String result(size + right.get_size(), '\0');
	for (size_t i = 0; i < size; ++i) {
		result.data[i] = data[i];
	}

	for (size_t i = 0; i < right.size; ++i) {
		result.data[size + i] = right.data[i];
	}
	result.data[result.size] = '\0';
	return result;
}

String& String::operator+=(const String& right) {
	*this = *this + right;
	return *this;
}

bool String::operator==(const String& right) const {
	if (size != right.size) {
		return false;
	}

	for (size_t i = 0; i < size; i++) {
		if (data[i] != right.data[i]) {
			return false;
		}
	}
	return true;
}

bool String::operator!=(const String& right) const {
	return !(*this == right);
}

bool String::operator>(const String& right) const {
	int i = 0;
	while (i <= size && data[i] == right.data[i]) {
		i++;
	}
	if (i == size && i == right.size) {
		return false;
	}
	return data[i] > right.data[i];
}

bool String::operator<=(const String& right) const {
	return !(*this > right);
}


bool String::operator<(const String& right) const {
	int i = 0;
	while (i <= size && data[i] == right.data[i]) {
		i++;
	}
	if (i == size && i == right.size) {
		return false;
	}
	return data[i] < right.data[i];
}

bool String::operator>=(const String& right) const {
	return !(*this < right);
}


char& String::operator[](size_t id) {
	return data[id];
}

char& String::at(size_t id) {
	if (id < 0 || id > size) {
		std::cout << "Error! String index is out of boundary!" << std::endl;
		exit(1);
	}
	return data[id];
}

size_t String::get_size() const {
	return size;
}

const char* String::c_str() const {
	return data;
}

String::~String() {
	delete [] data;
}


std::ostream& operator<<(std::ostream& left, const String& right) {
	left << right.c_str();
	return left;
}

