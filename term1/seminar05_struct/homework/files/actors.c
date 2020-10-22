#include <stdio.h>

struct date
{
	int day, month, year;
};
typedef struct date Date;


struct address
{
	char country[20];
	char region[20];
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


void print_actor(FILE* stream, const Actor* a)
{
	fprintf(stream, "%10s %10s. Height: %d cm. Birth date: %02d/%02d/%d. Birth Address: %s, %s, %s\n", a->name, a->surname,
		   a->height, a->birth_date.day, a->birth_date.month, a->birth_date.year, 
		   a->birth_address.country, a->birth_address.region, a->birth_address.city);
}

void print_actors(FILE* stream, const Actor* actors, int number_of_actors)
{
	for (int i = 0; i < number_of_actors; i++)
		print_actor(stream, &actors[i]);
	printf("\n");
}



// Находит самого высокого актёра и возращает структуру Actor
// Это не очень хороший способ решения этой задачи, так как происходят 
// необязательные множественные копировани структур Actor
// Например, в строке tallest = actors[i]; присходит копирование правой структуры в левую
// Это всё ведёт к более медленной работе функции
Actor get_tallest_actor(Actor* actors, int number_of_actors)
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
int get_tallest_id(Actor* actors, int number_of_actors)
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
Actor* get_tallest_pointer(Actor* actors, int number_of_actors)
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



int main()
{
	// Создаём и инициализируем массив из 10-ти актёров
	Actor actors[10] = { {"Ivan", "Ivanov",  0, 181, {5, 10, 1977},         {"Russia", "Moscow Oblast", "Dolgoprudny"}},
						 {"Olga", "Petrova", 1, 172, {17, 2, 1981},         {"Russia", "Chelyabinsk Oblast", "Miass"}},
						 {"John", "Stone", 0, 171,  {11, 8, 1986},          {"England", "East Sussex", "Rye"}},
						 {"Andrea", "Muller", 1, 165, {16, 1, 1996},        {"Germany", "Schleswig-Holstein", "Lubeck"}},
						 {"Isabella", "Rodriguez", 1, 161,  {11, 7, 1992},  {"Spain", "La Rioja", "Logrono"}},
						 {"Kane", "Sato", 0, 176,  {21, 12, 2001},          {"Japan", "Chiba Prefecture", "Mobara"}},
						 {"Saanvi", "Acharya", 1, 168,  {12, 4, 1992},      {"India", "Haryana", "Sonipat"}},
						 {"Wang", "Fang", 1, 161, {28, 9, 1999},            {"China", "Shandong", "Rizhao"}},
						 {"Agung", "Sari", 0, 170,  {14, 5, 2004},          {"Indonesia", "South Sumatra", "Palembang"}},
						 {"Zeida", "Molefe", 1, 182,  {6, 10, 2001},        {"Botswana", "North-East District", "Francistown"}},
	};

	// Печать на экран
	print_actors(stdout, actors, 10);

	// Печать в файл test.txt
	// FILE* fout = fopen("test.txt", "w");
	// print_actors(fout, actors, 10);
	// fclose(fout);


	// Пример использование 3-х вариантов функции поиска структуры
	Actor a = get_tallest_actor(actors, 10);
	print_actor(stdout, &a);

	int id = get_tallest_id(actors, 10);
	print_actor(stdout, &actors[id]);

	print_actor(stdout, get_tallest_pointer(actors, 10));
}