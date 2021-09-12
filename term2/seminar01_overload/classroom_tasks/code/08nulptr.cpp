#include <cstdio>


void print(int value) {
	printf("Int: %d\n", value);
}

void print(void* pointer) {
	printf("Pointer: %p\n", pointer);
}

int main() {
	// Новое специальное нулевое значение для указателя: nullptr
	// В языке C для этой цели использовался NULL, 
	// который был просто числом 0 (#define NULL 0LL), что плохо в некоторых ситуациях

	void* p1 = NULL;
	void* p2 = nullptr;

	// Всё ОК (компилятор может выбрать функцию):
	print(p1);
	print(p2);

	// Тут неверно (компилятор не может выбрать перегруженную функцию):
	print(NULL);

	// Тут всё OK:
	print(nullptr);
}