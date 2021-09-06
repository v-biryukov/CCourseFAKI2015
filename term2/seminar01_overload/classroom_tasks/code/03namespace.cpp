#include <cstdio>

/*
	Определяем переменные/структуры/функции внутри пространства имён mipt
	Затем к ним можно будет доступиться используя префикс mipt::
*/
namespace mipt {
	int number_of_students = 400;
	char faculty_name[] = "Fizteh-school of aerospace technologies";
	
	void print_faculty() {
		printf("Faculty: %s!\n", faculty_name);
	}


	struct Student {
		char name[50];
		float average_mark;
	};
	
	void print_student(Student s) {
		printf("Student name: %s. Student average mark: %f.", s.name, s.average_mark);
	}
}

/*
	Чтобы получить доступ к этим переменным/структурам/функциям
	вне пространства имён, нужно добавить к имени mipt::

*/

int main() {
	// Так не сработает
	// print_faculty();

	// Так сработает
	mipt::print_faculty();

	// Или так
	using namespace mipt;
	print_faculty();

	/*
	Задание:
	1) Создайте переменную типа Student и напечатайте её, используя print_student
	   (без использования using namespace mipt;)

	2) То же самое с использованием using namespace mipt
	*/
}