#include <stdio.h>

int main()
{
	
	char a = 97;
	short b = 12334;
	int c = 753;
	long d = 1234L;
	long long e = 753423LL;
	
	printf("char:      Value = %9hhd; Size = %d; Address = %p\n", a, sizeof(a), &a);
	printf("short:     Value = %9hd; Size = %d; Address = %p\n", b, sizeof(b), &b);
	printf("int:       Value = %9d; Size = %d; Address = %p\n", c, sizeof(c), &c);
	printf("long:      Value = %9ld; Size = %d; Address = %p\n", d, sizeof(d), &d);
	printf("long long: Value = %9lld; Size = %d; Address = %p\n", e, sizeof(e), &e);

	float f = 14.45f;
	double g = 48.334;
	printf("float:     Value = %9f; Size = %d; Address = %p\n", f, sizeof(f), &f);
	printf("double:    Value = %9lf; Size = %d; Address = %p\n", g, sizeof(g), &g);

	char* pa = &a;
	int* pc = &c;
	float* pf = &f;
	float* pg = &g;
	printf("char*:     Value = %9p; Size = %d; Address = %p\n", pa, sizeof(pa), &pa);
	printf("int*:      Value = %9p; Size = %d; Address = %p\n", pc, sizeof(pc), &pc);
	printf("float*:    Value = %9p; Size = %d; Address = %p\n", pa, sizeof(pf), &pf);
	printf("double*:   Value = %9p; Size = %d; Address = %p\n", pa, sizeof(pg), &pg);

	int array[80];
	// Имя массива передаётся в функция, как адрес на 0-й элемент
	printf("int array[80]:  Value = %p; Size = %d; Address = %p\n", array, sizeof(array), &array);
}