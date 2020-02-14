#include <cstdio>

struct Complex
{
	float re, im;
};

Complex operator+(Complex first, Complex second)
{
	Complex result = {first.re + second.re, first.im + second.im};
	return result;
}

int main()
{
	Complex z1 = {3, 7};
	Complex z2 = {2, -4};

	Complex z = z1 + z2;
	printf("%g + %gi\n", z.re, z.im);


	/*
	Задание:
	1) Перегрузите следующие операторы:
		1] Вычитание
		2] Умножение
		3] Деление
		4] Унарный минус
		5] Унарный плюс
		6] Сопряжение
		7] Сравнение ==
		8] Операторы +=, -=, *=, /=

	2) Напишите функции:
		1] exp(z)
		2] sin(z)
		3] norm(z) - возвращает норму комплексного числа

	/*
	z = z1 - z2;
	printf("%g + %gi\n", z.re, z.im);

	z = z1 * z2;
	printf("%g + %gi\n", z.re, z.im);

	z = z1 / z2;
	printf("%g + %gi\n", z.re, z.im);

	z = -z1;
	printf("%g + %gi\n", z.re, z.im);

	z = *z1; // (Комплексно-сопряжённое)
	printf("%g + %gi\n", z.re, z.im);

	z = exp(z1 + z2)/(z1 * z2);
	printf("%g + %gi\n", z.re, z.im);
	*/
}