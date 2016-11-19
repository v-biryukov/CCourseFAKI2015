
#include <stdio.h>
#include <string.h>

// FILE_LINE_LENGTH -- максимальная длина строки в файле
#define FILE_LINE_LENGTH 300

typedef struct team
{
	char team_name[50];
	int matches_played;
	int wins;
	int draws;
	int looses;
	int GF; // голов забито
	int GA; // голов пропущено
	int points;
} Team;


typedef struct match
{
	char team1[50];
	char team2[50];
	int goals1;
	int goals2;	
} Match;

// Функция, которая считывает все матчи из файла file_name
// и записывает всё в массив matches
void read_matches_from_file(char * file_name, Match * matches)
{
	// Открываем файл
	FILE * f = fopen(file_name, "r");
	// Разделители между словами: пробел и знак табуляци(т.е. TAB -- '\t')
	char delimiters[3] = " \t";
	// Строка, куда мы будем поочерёдно записывать строки из файла
	char line[FILE_LINE_LENGTH];
	// Номер текущей считываемой строки
	int match_num = 0;
	// С указателя token мы указываем на текущее "слово"
	// "Слово" -- это любая комбинация символ между разделителями
	char *token;
	
	// Читаем строки поочерёдно пока не достигнем конца файла
	while (fgets(line, FILE_LINE_LENGTH, f) != NULL)
	{
		token = strtok(line, delimiters); // Парсим первое "слово" из строки line -- это номер тура
		token = strtok(NULL, delimiters); // Парсим второе "слово" из строки line -- это дата. NULL означает, что мы считываем из той же строки 
		token = strtok(NULL, delimiters); // Парсим третье "слово" из строки line -- это время
		token = strtok(NULL, delimiters); // Парсим 4-е "слово" из строки line -- это имя команды
		strcpy(matches[match_num].team1, token);  // Копируем имя команды в нужное место в массиве matches
		token = strtok(NULL, delimiters); // Парсим 5-е "слово" из строки line -- это тире
		
		// Остальное сами
		// Чтобы распарсить счёт, можно сначала считать его как строку
		// а потом использовать функцию sscanf (в КР#2, задача parse)
		
		// ...

		// Дописать функцию тут

		// ...
		
		// Можно распечатать полученные матчи, для тестирования
		// printf("%s %s %d %d\n", matches[i].team1, matches[i].team2, matches[i].goals1, matches[i].goals2);
		
		// Переходим к следующей строке (т.е. к следующему матчу)
		match_num++;
	}
	fclose(f);
}


void calculate_team_scores(Match * matches, Team * teams)
{
	
	
}


int main()
{
	char * fname = "games.txt";
	Match matches[240];
	read_matches_from_file(fname, matches);

	return 0;
}

