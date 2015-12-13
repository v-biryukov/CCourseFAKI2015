#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// FILE_LINE_LENGTH -- максимальная длина строки в файле
#define FILE_LINE_LENGTH 300
// MAX_FEATURE_NAME_LENGTH -- максимальная длина имени признака
#define MAX_FEATURE_NAME_LENGTH 20


// Для удобства назовём тип такой строки: char[MAX_FEATURE_NAME_LENGTH] как string
typedef char string[MAX_FEATURE_NAME_LENGTH];  

// Эта структура описывает одну строчку из файла
typedef struct sample
{
	int * X; // признаки(features)
	int y;   // результат
} Sample;

// Структура введённая для удобства, в ней хранятся вся информация о нашей задачи
typedef struct info
{
	int num_of_features;             // число признаков -- в файле titanic -- 3 признака
	
	int num_of_samples;              // число сэмплов (строк в файле) -- в файле titanic -- 2200
	
	int * num_of_feature_outcomes;   // число возможных значений признаков, это динамический массив 
	                                 // массив из num_of_features элементов т.к. у каждого признака может быть разное число значений
	                                 //  -- в файле titanic это массив {4, 2, 2}
	
	string * features;               // названия признаков -- массив из num_of_features элементов
	                                 //  -- в файле titanic это массив {"pclass", "age", "sex"}
	
	string ** feature_outcomes;      // возможные значения признаков -- двумерный массив из num_of_features * num_of_feature_outcomes[i] элементов
	                                 //  -- в файле titanic это массив {{"1st", "2nd", "3rd", "crew"}, {"adult", "child"}, {"male", "female"}}
	
	int num_of_result_outcomes;      // число возможных значений результата
	                                 //  -- в файле titanic это 2
	
	string result;                   // название результата
	                                 //  -- в файле titanic это "survived"
	
	string * result_outcomes;        // возможные значения результата
	                                 //  -- в файле titanic это {"yes", no}
	
} Info;

// Дальше написано несколько функций, они считывают данные из файла, выделяют/освобождают память
// Разбираться в них необязательно

// Считывает информацию о задаче из файла
// file_name -- имя файла
// features_info -- в эту структуру записывается вся информация
void set_info_from_file(char * file_name, Info * features_info)
{
	
	char temp_string[100];
	FILE * f = fopen(file_name, "r");
	fscanf(f, "number_of_features=%d\n", &features_info->num_of_features);
	fscanf(f, "number_of_samples=%d\n", &features_info->num_of_samples);
	
	// printf("number_of_features = %d\n", features_info->num_of_features);
	// printf("number_of_samples = %d\n", features_info->num_of_samples);
	
	features_info->features = (string *)malloc(sizeof(string) * features_info->num_of_features);
	features_info->num_of_feature_outcomes = (int *)malloc(sizeof(int) * features_info->num_of_features);
	features_info->feature_outcomes = (string **)malloc(sizeof(string*) * features_info->num_of_features);
	
	fscanf(f, "%s", temp_string);
	int i;
	for (i = 0; i < features_info->num_of_features; ++i)
	{
		fscanf(f, "%s", features_info->features[i]);
	}
	
	fscanf(f, "%s", temp_string);
	fscanf(f, "%s", features_info->result);
	
	for (i = 0; i < features_info->num_of_features; ++i)
	{
		int n, j;
		fscanf(f, "%s", temp_string);
		fscanf(f, "%d", &n);
		features_info->num_of_feature_outcomes[i] = n;
		features_info->feature_outcomes[i] = (string *)malloc(sizeof(string) * n);
		
		// printf("%s\n", temp_string);
		
		for (j = 0; j < n; ++j)
		{
			
			fscanf(f, "%s", features_info->feature_outcomes[i][j]);
			// printf("\t%s\n", features_info->feature_outcomes[i][j]);
		}
	}
	
	int n, j;
	fscanf(f, "%s", temp_string);
	fscanf(f, "%d", &n);
	features_info->num_of_result_outcomes = n;
	features_info->result_outcomes = (string *)malloc(sizeof(string) * n);
	// printf("%s\n", temp_string);
	
	for (j = 0; j < n; ++j)
	{
		fscanf(f, "%s", features_info->result_outcomes[j]);
		// printf("\t%s\n", features_info->result_outcomes[j]);
	}
	
	fclose(f);
}

// Освобождает память выделенную на структуру Info
void free_info(Info * inf)
{
	free(inf->num_of_feature_outcomes);
	free(inf->features);
	free(inf->result_outcomes);
	
	int i;
	for (i = 0; i < inf->num_of_features; ++i)
	{
		free(inf->feature_outcomes[i]);		
	}
	free(inf->feature_outcomes);	
}

// Освобождает память выделенную на массив samples
void free_samples(Info * inf, Sample * samples)
{
	int i;
	for (i = 0; i < inf->num_of_samples; ++i)
	{
		free(samples[i].X);
	}
	free(samples);
}
// Считывает данные из файла
// file_name -- имя файла
// features_info -- эта структура импользуется при чтении из файла
// psamples в указатель *psamples хранится адрес выделенной памяти
void read_data_from_file(char * file_name, Info * features_info, Sample ** psamples)
{
	int i, j, k;
	char line[FILE_LINE_LENGTH];
	FILE * f = fopen(file_name, "r");
	fscanf(f, "%s", line);
	while (strcmp(line, "Data:"))
	{
		fscanf(f, "%s", line);
	}
	for (i = 0; i < features_info->num_of_features+1; ++i)
	{
		fscanf(f, "%s", line);
	}
	
	(*psamples) = (Sample *)malloc(features_info->num_of_samples * sizeof(Sample));
	
	char temp_str[MAX_FEATURE_NAME_LENGTH];
	for (i = 0; i < features_info->num_of_samples; ++i)
	{
		(*psamples)[i].X = (int *)malloc(sizeof(int) * features_info->num_of_features);
		for (j = 0; j < features_info->num_of_features; ++j)
		{
			fscanf(f, "%s", temp_str);
			for (k = 0; k < features_info->num_of_feature_outcomes[j]; ++k)
			{
				if (!strcmp(features_info->feature_outcomes[j][k], temp_str))
					break;
			}
			(*psamples)[i].X[j] = k;
		}
		fscanf(f, "%s", temp_str);
		for (k = 0; k < features_info->num_of_result_outcomes; ++k)
		{
			if (!strcmp(features_info->result_outcomes[k], temp_str))
				break;
		}
		(*psamples)[i].y = k;
	}
}




// Эта структура представляет собой узел дерева
typedef struct node
{
	int feature_id;           // Номер признака, который рассматривается в этом дереве
	
	int number_of_children;   // Число детей у этого узла
	struct node * children;   // Динамический массив, состоящий из узлов -- детей этого узла
	
	// int is_final;  является ли этот узел конечным -- необязательное поле, т.к. это можно проверить как number_of_children == 0
	int result;               // если этот узел конечный -- то тут хранится результат
} Node;


// Рекурсивная функция для печати дерева
// Вам нужно создать аналогичную функцию для создания дерева
void print_tree(Node * pn, Info * info, int depth)
{
	if (pn)
	{
		int i;
		// Печатаем сам узел
		for (i = 0; i < depth; ++i)
			printf ("\t");
		printf ("feature - %s:", info->features[pn->feature_id]);
		if (pn->number_of_children == 0)
		{
			printf (" result %d:", pn->feature_id);
		}
		printf("\n");
		// Печатаем всех его детей
		
		for ( i = 0; i < pn->number_of_children; ++i )
			print_tree(&pn->children[i], info, depth+1);
	}	
}

// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// Далее -- ваши функции
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||



// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

int main()
{
	char * file_name = "titanic.txt";
	Info info;
	Sample * samples;
	// Считываем всё из файла и записываем в features_info и samples
	set_info_from_file(file_name, &info);
	read_data_from_file(file_name, &info, &samples);
	
	// Теперь в info хранится вся информация о задачи
	// Например в info.feature_outcomes[0][0] - хранится 1-е значение 1-го признака
	// Для задачи titanic это -- строка "1st"
	
	// В массиве samples хранятся номера признаков и номер результата
	// Например samples[100] может содержать:
	// samples[100].X = {0,              1,            0    } -- это означает, что это:
 	//                   1-й класс     ребёнок      мальчик
 	// samples[100].y = 1, означает что он выжил -- survived = "yes"
	
	
	// Создаём корень дерева
	Node root;
	
	// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	// Следующий ниже код -- подсказка
	// После того, как вы в нём разбирётесь его можно будет удалить
	// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	// Чтобы создать, например, 3-х его детей нужно выделить на них память с помощью malloc:
	root.feature_id = 0;
	root.number_of_children = 3;
	root.children = (Node *)malloc(root.number_of_children * sizeof(Node));
	// У детей другие признаки:
	int i;
	for (i = 0; i < 3; ++i)
	{
		root.children[i].feature_id = 1;
	}
	// Создадим ещё 3-х внуков узла root:
	root.children[0].number_of_children = 3;
	root.children[0].children = (Node *)malloc(root.children[0].number_of_children * sizeof(Node));
	// У внуков другие признаки:
	for (i = 0; i < 3; ++i)
	{
		root.children[0].children[i].feature_id = 2;
	}
	
	// Можно напечатать содержимое дерева
	print_tree(&root, &info, 0);
	
	// Не забывайте удалять память, выделенную с помощью malloc вот так:
	free(root.children);
	free(root.children[0].children);
	
	// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	// Далее -- ваш код
	// Но, наверное потребуется создать несколько рекурсивных функций вне функции main(или одну)
	// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	
	
	
	
	
	
	







	
	
	
	
	
	
	
	// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	free_samples(&info, samples);
	free_info(&info);
	return 0;
}
