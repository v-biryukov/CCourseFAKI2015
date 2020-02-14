#include <cstdio>

int main()
{
	int a = 123;

	int& r = a;

	printf("1) Variable a = %d. Reference r = %d\n", a, r);
	a += 1;
	printf("2) Variable a = %d. Reference r = %d\n", a, r);
	r += 2;
	printf("3) Variable a = %d. Reference r = %d\n", a, r);


	int arr[] = {4, 8, 15, 16, 23, 42};
	/*
		Создайте ссылку на элемент массива и измените его, используя только ссылку
	*/
}