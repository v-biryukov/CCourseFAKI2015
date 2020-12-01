#include <stdio.h>

int main()
{
	FILE* f = fopen("test.txt", "r");
	while (1)
	{
		// Считываем 1 символ
		int c = fgetc(f);

		// fgetc возвращает ASCII код символа
		// или EOF, если дошли до конца файла
		if (c == EOF)
			break;

		printf("%c\n", c);
	}

	// Перематываем на начало файла
	fseek(f, 0, SEEK_SET);

	// То же самое, но более кратко
	int c;
	while ((c = fgetc(f)) != EOF)
	{
		printf("%c\n", c);
	}

	fclose(f);

}