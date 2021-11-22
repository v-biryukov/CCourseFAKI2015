#include <stdio.h>
int main()
{
	char a[5] = "Lion";
	char b[5];
	
	// Теперь будет считывать не более 5 символов 
	// (включая нулевой на конце строки)
	fgets(b, 5, stdin);
	
	printf("a = %s\n", a);
	printf("b = %s\n", b);
}