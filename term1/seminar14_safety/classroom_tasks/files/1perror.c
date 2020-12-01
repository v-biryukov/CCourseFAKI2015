#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	perror("Error");

	// Неправильная работа с математическими функциями
	float x = sqrt(-1);
	perror("Error");

	// Выделяем больше чем нужно
	int* p = (int*)malloc(10000000000000);
	perror("Error");

	// Пытаемся открыть файл, который не существует
	FILE* f1 = fopen("non_existed_file.txt", "r");
	perror("Error");

	// Неправильный режим открытия файла (z)
	FILE* f2 = fopen("abc.txt", "z");
	perror("Error");
}