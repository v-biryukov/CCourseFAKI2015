
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

// FILE_LINE_LENGTH -- максимальная длина строки в файле
#define FILE_LINE_LENGTH 300

typedef struct player
{
	char surname[50];
	char name[50];
	char position;
	int start_year;
	int finish_year;
} Player;

// Функция, которая считывает всех игроков из файла file_name
// и записывает всё в массив players
void read_players_from_file(char * file_name, Player * players)
{
	// Открываем файл
	FILE * f = fopen(file_name, "r");
	// Проверяем на ошибки открытия
	if ( f != NULL )
	{
		printf( "Error while opening file\n" );
		fclose (f);
		exit(1);
	}
	// Разделители между словами: пробел, запятая и знак табуляци(т.е. TAB -- '\t')
	char delimiters[3] = ", \t";
	// Строка, куда мы будем поочерёдно записывать строки из файла
	char line[FILE_LINE_LENGTH];
	// Номер текущей считываемой строки
	int player_num = 0;
	// С указателя token мы указываем на текущее "слово"
	// "Слово" -- это любая комбинация символ между разделителями
	char *token;
	
	// Читаем строки поочерёдно пока не достигнем конца файла
	while ( fgets(line, FILE_LINE_LENGTH, f) != NULL)
	{
		
		token = strtok(line, delimiters); // Парсим первое "слово" из строки line -- это фамилия
		strcpy(players[player_num].surname, token);  // Копируем имя команды в нужное место в массиве matches
		token = strtok(NULL, delimiters); // Парсим второе "слово" из строки line -- это имя. NULL означает, что мы считываем из той же строки 
		strcpy(players[player_num].name, token);  // Копируем имя команды в нужное место в массиве matches
		fgets(line, FILE_LINE_LENGTH, f); // Считываем следующую строку
		
		// Остальное сами
		
		// ...

		// Дописать функцию тут

		// ...
		
		// Можно распечатать полученных игроков, для тестирования
		// printf("%s %s %c %d %d\n", players[i].surname, players[i].name, players[i].position, matches[i].start_year, matches[i].finish_year);
		
		// Переходим к следующей строке (т.е. к следующему игроку)
		player_num++;
	}
	fclose(f);
}



int main()
{
	char * fname = "players.txt";

	return 0;
}

