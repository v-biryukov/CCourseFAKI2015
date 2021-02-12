#include <cstdio>

// Определяем переменные/структуры/функции внутри 
// пространства имён fakt
namespace fakt
{
	int number_of_students = 400;
	char faculty_name[] = "Fizteh-school of aerospace technologies";
	void print_faculty()
	{
		printf("Faculty: %s!\n", faculty_name);
	}


	struct Student
	{
		char name[50];
		float average_mark;
	};
	void print_student(Student s)
	{
		printf("Student name: %s. Student average mark: %f.", s.name, s.average_mark);
	}
}

// Чтобы получить доступ к этим переменным/структурам/функциям
// вне пространства имён, нужно добавить к имени fakt::

int main()
{
	// Так не сработает
	// print_faculty();

	// Так сработает
	fakt::print_faculty();

	// Или так
	using namespace fakt;
	print_faculty();

	// Задание:
	// 1) Создайте переменную типа Student и напечатайте её, используя print_student
	//    (без использования using namespace fakt;)

	// 2) То же самое с использованием using namespace fakt
}