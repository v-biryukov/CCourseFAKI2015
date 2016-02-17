#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main()
{
	int n;
	scanf("%d", &n);
	int answers[255];
	for (int i = 0; i < n; ++i)
		scanf("%d", &answers[i]);
	bool is_curent_knight = true;
	int count_min = 255;
	int count;
	for (int i = 0; i < 2; ++i)
	{
		count = 0;
		is_curent_knight = (bool)i;
		for (int j = 0; j < n; ++j)
		{
			if (is_curent_knight)
				count++;
			is_curent_knight = is_curent_knight ? (bool)answers[j] : !(bool)answers[j];
		}
		if ((int)is_curent_knight == i)
			if (count < count_min)
				count_min = count;

	}
	printf("%d\n", count_min);
}
