#include <iostream>
#include <string>

using namespace std;

// Базовый класс
// Используем protected вместо private, чтобы класс Cat мог использовать поля name и age
class Animal
{
protected:
	std::string name;
	int age;
public:
	Animal()
	{
	}
	Animal(std::string name, int age) : name(name), age(age) 
	{
	}

	virtual void say()
	{
		cout << "<abstract sound> Name = " << name << " age = " << age << endl;
	}

	void increase_age()
	{
		age++;
	}
};

// Класс, который наследуется от Animal
class Cat : public Animal
{
private:
	// Предположим, что мы захотели выделить что-то динамически
	// В данном случае, гораздо лучше было бы использовать std::vector

	int number_of_days;
	int* mouses_caught_by_day;
public:
	// Конструктор Cat вызывает конструктор Animal
	Cat(std::string name, int age, int number_of_days_in, int* mouses_caught_by_day_in) 
		: Animal(name, age), number_of_days(number_of_days_in)
	{
		mouses_caught_by_day = new int[number_of_days];
		for (int i = 0; i < number_of_days; i++)
			mouses_caught_by_day[i] = mouses_caught_by_day_in[i];
	}

	void say()
	{
		cout << "Meow! My name is " << name <<". I am " << age << " old. "; 
		cout << "I caught ";
		for (int i = 0; i < number_of_days; i++) 
			cout << mouses_caught_by_day[i] << " ";
		cout << "mouses!" << endl;
	}

	// Освобождаем память
	~Cat()
	{
		delete [] mouses_caught_by_day;
	}
};


int main()
{
	int daily_mouses[5] = {5, 3, 6, 5, 7};
	Animal* panimal = new Cat("Tomas", 8, 5, daily_mouses);
	panimal->say();

	// Найдите ошибку в этой программе (утечка памяти)
	// И исправьте её
}