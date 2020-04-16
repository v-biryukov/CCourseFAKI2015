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
	Animal(std::string name, int age) : name(name), age(age) 
	{
	}

	void say()
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
	int number_of_mouse_caught;
public:
	// Конструктор Cat вызывает конструктор Animal
	Cat(std::string name, int age, int x) : Animal(name, age), number_of_mouse_caught(x)
	{
	}

	void say()
	{
		cout << "Meow! My name is " << name <<". I am " << age << " old. "; 
		cout << "I caught " << number_of_mouse_caught << " mouses!" << endl;
	}

	void catch_mouse()
	{
		number_of_mouse_caught++;
	}
};



int main()
{
	Animal animal("None", 100);
	Cat cat("Murka", 10, 77);

	// Задание 1:
	// Будет ли работать код ниже и, если да, то что он напечатает?
	// cat = animal;
	// cat.say();

	// Задание 2:
	// Будет ли работать код ниже и, если да, то что он напечатает?
	// animal = cat;
	// animal.say();


	Animal* panimal = new Animal("None", 100);
	Cat* pcat = new Cat("Murka", 10, 77);

	// Задание 3:
	// Будет ли работать код ниже и, если да, то что он напечатает?
	// pcat = panimal;
	// pcat->say();

	// Задание 4:
	// Будет ли работать код ниже и, если да, то что он напечатает?
	// panimal = pcat;
	// panimal->say();

}