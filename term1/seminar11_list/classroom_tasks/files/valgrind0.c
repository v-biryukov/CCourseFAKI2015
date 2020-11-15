#include <stdlib.h>
int main()
{
	char* p = (char*)malloc(100);
	p = (char*)malloc(20);
	free(p);
}