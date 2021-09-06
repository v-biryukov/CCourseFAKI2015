#include <cstdio>

// Ссылки, как и указатели используются для передачи аргументов в функции

// Передача по значению
void add5_naive(int a) {
	a += 5;
}

// Передача по указателю
void add5_pointer(int* p) {
	*p += 5;
}

// Передача по ссылке
void add5_reference(int& a) {
	a += 5;
}

int main() {
	int a = 10;

	printf("1) Initial a = %d\n", a);
	
	add5_naive(a);
	printf("2) After add5_naive a = %d\n", a);

	// Передаём адрес
	add5_pointer(&a);
	printf("3) After add5_pointer a = %d\n", a);

	// Передаём по ссылке
	add5_reference(a);
	printf("4) After add5_reference a = %d\n", a);

	/* 
	Задание:
		1) Написать функцию: swap(int* pa, int* pb) - которая меняет местами a и b

		2) Написать аналогичную функцию с использованием ссылок
		
		3) Вызвать обе функции из main() и проверить их
	*/
}