#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* get_string()
{
	char message[100] = "Hello world!";
	char* p = message;
	return p;
}


int main()
{
	printf("String: %s\n", get_string());
	return 0;
}
