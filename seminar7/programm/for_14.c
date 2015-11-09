#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	// Считываем строку
	char s[4001];
	scanf("%4001s", s);
	int count = 0;
	
	// Проходим по этой строке
	for (int i = 0; i < strlen(s); ++i)
	{
		if (s[i] == '(')
			count++;
		else if (s[i] == ')')
			count--;
		if (count < 0)
			break;
	}
	if (count == 0)
		printf("YES\n");
	else
		printf("NO\n");
	
}
