#include <stdio.h>
#include <string.h>

struct date
{
	int day, month, year;
};
typedef struct date Date;


struct address
{
	char country[10];
	char region[30];
	char city[20];
};
typedef struct address Address;


struct actor
{
	char name[32];
	char surname[32];
	int gender; // пол: 0 - мужской, 1 - женский
	int height;
	Date birth_date;
	Address birth_address;
};
typedef struct actor Actor;


// Функция, которая печатает информацию об одном актере
// 1) stream -- поток. Это может быть один из файлов, созданный с помощью fopen
// 		либо это может быть stdout. Тогда функция напечатает всё не в файл, а на экран (как printf)
// 2) a -- указатель на структуру актёр. Модификатор const означает, что мы не сможем поменять
// 		значение того, на что указывает a
void print_actor(FILE* stream, const Actor* a) 
{
	fprintf(stream, "%12s %15s. Height: %d cm. Birth date: %02d/%02d/%d. Birth Address: %s, %s, %s\n", a->name, a->surname,
		   a->height, a->birth_date.day, a->birth_date.month, a->birth_date.year, 
		   a->birth_address.country, a->birth_address.region, a->birth_address.city);
}

// Функция, которая считывает актёров из файла под названием filename в массив actors
// и возвращает количество актёров
// Необходимо, чтобы количество актёров в файле не превышало размер массива actors
// Иначе будет ошибка. Как это обойти мы рассмотрим во второй части 1-го семестра
int read_actors_from_file(const char filename[], Actor actors[])
{
	FILE* fin = fopen(filename, "r");
	int number_of_actors;
	fscanf(fin, "%d", &number_of_actors);

	for (int i = 0; i < number_of_actors; ++i) 
	{
		fscanf(fin, "%[^,],%[^,],%d,%d,%d/%d/%d,%[^,],%[^,],%[^\n]\n",
			actors[i].name, actors[i].surname, &actors[i].gender, &actors[i].height,
			&actors[i].birth_date.day, &actors[i].birth_date.month, &actors[i].birth_date.year, 
			actors[i].birth_address.city, actors[i].birth_address.region, actors[i].birth_address.country);
	}
	fclose(fin);
	return number_of_actors;
}

// Находит самого высокого актёра и возращает структуру Actor
// Это не очень хороший способ решения этой задачи, так как происходят 
// необязательные множественные копировани структур Actor
// Например, в строке tallest = actors[i]; присходит копирование правой структуры в левую
// Это всё ведёт к более медленной работе функции
Actor get_tallest_actor(Actor actors[], int number_of_actors) 
{
	Actor tallest = {};
	if (number_of_actors == 0)
		return tallest;

	for (int i = 0; i < number_of_actors; ++i) 
	{
		if (actors[i].height > tallest.height)
			tallest = actors[i];
	}
	return tallest;
}


// Находит самого высокого актёра и возращает его индекс (т.е. его номер в массиве actors)
// Хорошее решение задачи
int get_tallest_id(Actor actors[], int number_of_actors)
{
	if (number_of_actors == 0)
		return -1;

	int tallest_id = 0;
	for (int i = 1; i < number_of_actors; ++i) 
	{
		if (actors[i].height > actors[tallest_id].height)
			tallest_id = i;
	}
	return tallest_id;
}

// Находит самого высокого актёра и возращает указатель на него
// Хорошее решение задачи
Actor* get_tallest_pointer(Actor actors[], int number_of_actors)
{
	if (number_of_actors == 0)
		return NULL;

	Actor* p_tallest = &actors[0];

	for (int i = 1; i < number_of_actors; ++i) 
	{
		if (actors[i].height > p_tallest->height)
			p_tallest = &actors[i];
	}
	return p_tallest;
}



void print_all_actors_by_birth_year(Actor actors[], int number_of_actors, int year)
{
	for (int i = 0; i < number_of_actors; ++i) 
	{
		if (actors[i].birth_date.year == year) 
			print_actor(stdout, actors + i);
	}
}


int main()
{
	// Создаём и инициализируем массив из актёров
	Actor actors[2000];
	
	// Считываем актёров (главное, чтобы их было не больше 2000)
	int number_of_actors = read_actors_from_file("actors.csv", actors);

	// Печатаем всех актёров с датой рождения = 1981
	print_all_actors_by_birth_year(actors, number_of_actors, 1981);
}