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


void print_actor(FILE* stream, const Actor* a)
{
	fprintf(stream, "%12s %15s. Height: %d cm. Birth date: %02d/%02d/%d. Birth Address: %s, %s, %s\n", a->name, a->surname,
		   a->height, a->birth_date.day, a->birth_date.month, a->birth_date.year, 
		   a->birth_address.country, a->birth_address.region, a->birth_address.city);
}

void print_actors(FILE* stream, const Actor* actors, int number_of_actors)
{
	for (int i = 0; i < number_of_actors; i++)
		print_actor(stream, &actors[i]);
	printf("\n");
}

// Считывает актёров и возвращает их количество
int read_actors_from_file(char* filename, Actor* actors)
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
	return number_of_actors;
}


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


void print_all_actors_with_name(Actor* actors, int number_of_actors, char* name)
{
	for (int i = 0; i < number_of_actors; ++i)
	{
		if (strcmp(actors[i].name, name) == 0)
			print_actor(stdout, actors + i);
	}
}


void print_all_actors_by_year(Actor* actors, int number_of_actors, int year)
{
	for (int i = 0; i < number_of_actors; ++i)
	{
		if (actors[i].birth_date.year == year)
			print_actor(stdout, actors + i);
	}
}

void print_all_actors_by_height(Actor* actors, int number_of_actors, int min_height)
{
	for (int i = 0; i < number_of_actors; ++i)
	{
		if (actors[i].height > min_height)
			print_actor(stdout, actors + i);
	}
}


int main()
{
	// Создаём и инициализируем массив из актёров
	Actor actors[2000];
	// Считываем актёров (главное, чтобы их было не больше 2000)
	int number_of_actors = read_actors_from_file("actors.csv", actors);

	print_actor(stdout, get_tallest_pointer(actors, number_of_actors));

	printf("Size = %llu\n", sizeof(actors));
}