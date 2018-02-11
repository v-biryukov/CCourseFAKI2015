#include <stdio.h>

extern int myfunc();

int main()
{
	printf("result = %d\n", myfunc());
	return 0;
}
