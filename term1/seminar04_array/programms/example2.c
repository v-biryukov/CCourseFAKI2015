#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char s[1001];
	scanf("%1001s", s);
	for (int i = 0; i < strlen(s); ++i)
	{
		if (s[i] == 'a')
			s[i] = 'o';
	}
	printf("%s\n", s);
}
