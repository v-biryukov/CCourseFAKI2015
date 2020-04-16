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
		cout << "Constructor of Animal" << endl;
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
		cout << "Constructor of Cat" << endl;
	}

	void say()
	{
		cout << "Meow! My name is " << name <<". I am " << age << " old. "; 
		cout << "I caught " << number_of_mouse_caught << " mouses!" << endl;
	}

	void mouse_caught()
	{
		number_of_mouse_caught++;
	}
};

int main()
{
	Animal abstract("None", 100);
	Cat murka("Murka", 10, 77);


	// Задание 1: Что напечатают следующие строки?
	// abstract.say();
	// murka.say();

	// Задание 2: Будет ли работать код ниже? Ведь метод increase_age не описан в классе Cat
	// murka.increase_age();
	// murka.say();

	// Задание 3:
	// Что будет, если в классе Animal protected изменить на private?

	// Задание 4:
	// Будет ли работать код ниже и, если да, то что он напечатает?
	// murka = abstract;
	// murka.say();

	// Задание 5:
	// Будет ли работать код ниже и, если да, то что он напечатает?
	// abstract = murka;
	// abstract.say();

	// Задание 6:
	// Вызовите из функции say() класса Cat функцию say() класса Animal
}