#include <cstdio>

// Функция, которая возвращает ссылку
int& increase(int& a)
{
	a += 1;
}

int main()
{
	int a = 10;

	printf("1) Initial variable a = %d\n", a);


	// Что напечатает следующий участок кода:
	increase(a);
	printf("2) a = %d\n", a);

	increase(a) += 7;
	printf("3) a = %d\n", a);

	increase(increase(increase(a)));
	printf("4) a = %d\n", a);

}