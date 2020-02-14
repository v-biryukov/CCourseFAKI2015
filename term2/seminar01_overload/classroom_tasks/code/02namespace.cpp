#include <cstdio>

namespace fakt
{
	char faculty_name[] = "Fizteh-school of aerospace technologies";

	struct Student
	{
		char name[50];
		float average_mark;
	};

	void print_faculty()
	{
		printf("Faculty: %s!\n", faculty_name);
	}

	void print_student(Student s)
	{
		printf("Student name:%s. Student average mark: %f.", s.name, s.average_mark);
	}
}




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
	// 1) Создайте переменную типа Student и напечатайте её, используя fakt::print_student
	//    (без использования using namespace fakt;)

	// 2) То же самое с использованием using namespace fakt
}