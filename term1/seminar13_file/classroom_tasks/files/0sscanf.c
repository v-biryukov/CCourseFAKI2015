#include <stdio.h>


int main()
{
	char str[20] = "5-10-1872";
	int day, month, year;

	// Считываем числа из строки
	sscanf(str, "%d-%d-%d", &day, &month, &year);

	printf("Day: %d. Month: %d. Year: %d.\n", day, month, year);

	// Аналогично -- sprintf(строка, <то же самое, что и в printf>)
}