#include <stdio.h>
int main()
{
	FILE* f = fopen("test.txt", "r");
	fseek(f, 10, SEEK_SET); // Перемещаемся на 11-й символ
	fseek(f, -1, SEEK_END); // Перемещаемся к последнему символу

	printf("%c\n", fgetc(f));
	
	fseek(f, -1, SEEK_CUR); // Перемещаемся на 1 символ назад
	printf("%d\n", ftell(f));
	fseek(f, 0, SEEK_SET);  // Возвращаемся к началу
	fclose(f);
}