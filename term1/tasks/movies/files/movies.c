/*
    В данной программе мы считываем содержимое файлов actors.csv и movies.csv в одну структуру MovieDatabase.
    Структура MovieDatabase это примитивная база данных, в которой хранятся данные о фильмах и актёрах.
    
    Структура Actor состоит из следующих полей:

        1)  name        - имя актёра
        2)  surname     - фамилия актёра
        3)  gender      - пол, 0 - мужской, 1 - женский (тут можно было использовать enum)
        4)  height      - высота актёра в сантиметрах
        5)  birth_date  - дата рождения, структура, которая состоит из трёх полей типа int
        6)  birth_address - место рождения, структура, которая состоит из трёх полей - строк.


    Структура Movie состоит из следующих полей:

        1)  title        - название фильма
        2)  release_date - дата выхода, структура типа Date
        3)  rating       - рейтинг фильма, число от 0 до 10
        4)  crew_size    - количество актёров, сыгравших в фильме
        5)  crew         - массив, содержащий индексы актёров из массива, в котором хранятся актёры

    Структура MovieDatabse состоит из следующих полей:

        1)  number_of_movies    - количество фильмов в базе
        2)  movies              - указатель на массив фильмов в куче
        3)  number_of_actors    - количество актёров в базе
        4)  actors              - указатель на массив актёров в куче


    Были написаны функции для работы с этими структурами:


        get_number_of_lines:

            Вспомогательная функция. Вычисляет количество строк в файле.
            Нужна чтобы определить количество строк в csv файлах.
            Предполагается, что csv файлы корректны и там нет пустых строк и строк-комментариев.


        init_database:

            Возвращает базу данных не содержащую ни одного элемента.

        read_actors_from_file:

            Эта функция принимает на вход название файла и указатель на первый элемент массива структур Actor и
            количество актёров, которые нужно считать из файла в массив структур типа Actor.
            Функция считывает всех актёров из файла в массив.


        read_movies_from_file:

            Эта функция принимает на вход название файла и указатель на первый элемент массива структур Movie и
            количество фильмов, которые нужно считать из файла в массив структур типа Movie.
            Функция считывает все фильмы из файла в массив и возвращает количество считанных фильмов.


        read_database:

            Эта функция принимает на вход названия файлов в которых хранятся данные о актёрах и фильмах.
            А также эта функция принимает указатель на структуру типа MovieDatabase.
            Функция выделяет необходимую память в куче и считывает все данные из файлов в выделенную память.
            Указатели на память в куче будут сохранены в структуре типа MovieDatabase.

        clear_database:

            Очищает базу данных. При этом освобождает всю память, связанную с этой базой данных.

        
        print_actor:

            Печатаем данные об одном актёре в поток stream. stream может быть или файлом или stdout.

        print_movie:

            Печатаем данные об одном фильме в поток stream. stream может быть или файлом или stdout.

        print_movie_descriptive

            Печатаем подробные данные об одном фильме в поток stream. stream может быть или файлом или stdout.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct date
{
    int day, month, year;
};
typedef struct date Date;


struct address
{
    char country[12];
    char region[52];
    char city[32];
};
typedef struct address Address;


struct actor
{
    char name[32];
    char surname[32];
    int gender;
    int height;
    Date birth_date;
    Address birth_address;
};
typedef struct actor Actor;


struct movie
{
    char title[50];
    Date release_date;
    double rating;

    int crew_size;
    int crew[20];
};
typedef struct movie Movie;


struct movie_database
{
    int number_of_movies;
    Movie* movies;

    int number_of_actors;
    Actor* actors;
};
typedef struct movie_database MovieDatabase;



int get_number_of_lines(const char* filename)
{
    FILE* fin = fopen(filename, "r");
    if (fin == NULL)
    {
        fprintf(stdout, "Error. Can't open file %s!", filename);
        exit(1);
    }
    int number_of_lines = 0;

    while (1)
    {
        int c = fgetc(fin);

        if (c == EOF)
            break;

        if (c == '\n')
            number_of_lines += 1;
    }
    fclose(fin);

    return number_of_lines;
}


void read_actors_from_file(const char* filename, Actor* actors, int number_of_actors)
{
    FILE* fin = fopen(filename, "r");
    if (fin == NULL)
    {
        fprintf(stdout, "Error. Can't open file %s!", filename);
        exit(1);
    }

    for (int i = 0; i < number_of_actors; ++i) 
    {
        fscanf(fin, "%[^,],%[^,],%i,%i,%i/%i/%i,%[^,],%[^,],%[^\n]\n",
            actors[i].name, actors[i].surname, &actors[i].gender, &actors[i].height,
            &actors[i].birth_date.day, &actors[i].birth_date.month, &actors[i].birth_date.year, 
            actors[i].birth_address.country, actors[i].birth_address.region, actors[i].birth_address.city);

    }
    fclose(fin);
}



void read_movies_from_file(const char* filename, Movie* movies, int number_of_movies)
{
    FILE* fin = fopen(filename, "r");
    if (fin == NULL)
    {
        fprintf(stdout, "Error. Can't open file %s!", filename);
        exit(1);
    }


    for (int i = 0; i < number_of_movies; ++i)
    {
        
        fscanf(fin, "%[^,],%i/%i/%i,%lf,%i,", movies[i].title, &movies[i].release_date.day, 
            &movies[i].release_date.month, &movies[i].release_date.year, &movies[i].rating, &movies[i].crew_size);
        for (int j = 0; j < movies[i].crew_size; ++j)
        {
            fscanf(fin, "%i", &movies[i].crew[j]);
        }
    }
    fclose(fin);
}


MovieDatabase init_database()
{
    MovieDatabase md;
    md.number_of_actors = 0;
    md.number_of_movies = 0;
    md.actors = NULL;
    md.movies = NULL;
    return md;
}


void read_database(MovieDatabase* pmd, const char* actors_file_name, const char* movies_file_name)
{
    pmd->number_of_actors = get_number_of_lines("actors.csv");
    pmd->number_of_movies = get_number_of_lines("movies.csv");

    pmd->actors = (Actor*)malloc(sizeof(Actor) * pmd->number_of_actors);
    pmd->movies = (Movie*)malloc(sizeof(Movie) * pmd->number_of_movies);

    read_actors_from_file(actors_file_name, pmd->actors, pmd->number_of_actors);
    read_movies_from_file(movies_file_name, pmd->movies, pmd->number_of_movies);

    printf("AAAA %i %i", pmd->number_of_actors, pmd->number_of_movies);
}

void clear_database(MovieDatabase* pmd)
{
    free(pmd->actors);
    free(pmd->movies);
    *pmd = init_database();
}


void print_actor(FILE* stream, const Actor* a)
{
    fprintf(stream, "%10s %15s. Height: %i cm. Birth date: %02i/%02i/%i. Birth Address: %s, %s, %s\n", a->name, a->surname,
           a->height, a->birth_date.day, a->birth_date.month, a->birth_date.year, 
           a->birth_address.country, a->birth_address.region, a->birth_address.city);
}


void print_movie(FILE* stream, const Movie* a)
{
    fprintf(stream, "%20s. Rating: %.3lf. Release date: %02i/%02i/%i.\n", a->title, a->rating,
            a->release_date.day, a->release_date.month, a->release_date.year);
}


void print_movie_descriptive(FILE* stream, const MovieDatabase* pmd, int movie_id)
{
    if (movie_id < 0 || movie_id >= pmd->number_of_movies)
    {
        fprintf(stream, "Error. No movie with such id!\n");
        return;
    }
    print_movie(stdout, &pmd->movies[movie_id]);
    printf("Actors:\n");
    for (int i = 0; i < pmd->movies[movie_id].crew_size; ++i)
    {
        printf("\t");
        print_actor(stdout, &pmd->actors[pmd->movies[movie_id].crew[i]]);
    }
    printf("\n");
}


int main()
{
    MovieDatabase md = init_database();
    read_database(&md, "actors.csv", "movies.csv");

    while (1)
    {
        printf("Enter movie id (less than %i):\n", md.number_of_movies);
        int id;
        scanf("%i", &id);
        print_movie_descriptive(stdout, &md, id);
    }

    clear_database(&md);
}