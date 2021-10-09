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
		cout << "<abstract sound> Name = " << name << endl;
	}
};

// Класс, который наследуется от Animal
class Cat : public Animal
{
private:
	int number_of_mouse_caught;
public:
	Cat(std::string name, int age, int x) : Animal(name, age), number_of_mouse_caught(x)
	{
		cout << "Constructor of Cat" << endl;
	}

	void say()
	{
		cout << "Meow! My name is " << name << endl;
	}
};

int main()
{
	Animal abstract("None", 100);
	Cat murka("Murka", 10, 55);
	murka.say();

	// Приравнивание экземпляров классов друг к другу
	cout << "\tTask 1:" << endl;

	/* //Будет ли работать код ниже и, если да, то что он напечатает?
	murka = abstract;
	murka.say();
	/**/

	/* //Будет ли работать код ниже и, если да, то что он напечатает?
	abstract = murka;
	abstract.say();
	/**/

	// Приравнивание указателей на экземпляры классов друг к другу
	cout << "\tTask 2:" << endl;

	Animal* panimal = &abstract;
	Cat* pcat = &murka;

	/* //Будет ли работать код ниже и, если да, то что он напечатает?
	pcat = panimal;
	pcat->say();
	/**/

	/* //Будет ли работать код ниже и, если да, то что он напечатает? 
	panimal = pcat;
	panimal->say();
	/**/

	// Хотелось бы, чтобы в последнем случае panimal->say() вызывал бы метод say класса Cat и
	// печатал бы "Meow! My name is Murka". Как этого добиться?
}