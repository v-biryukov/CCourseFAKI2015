#include <stdio.h>


int main()
{
	int a = 287454020; // Это число = 0x11223344 в шестнадцатеричной системе

	// Сохраняем число a в текстовом формате
	FILE* ft = fopen("number.txt", "w");
	fprintf(ft, "%d", a);
	fclose(ft);

	// Сохраняем число a в бинарном формате
	FILE* fb = fopen("number.bin", "w");
	fwrite(&a, 1, 4, fb);
	fclose(fb);
}