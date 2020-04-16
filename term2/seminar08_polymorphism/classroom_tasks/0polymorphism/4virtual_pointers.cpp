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
	Cat cat("Murka", 10, 777);


	cout << "Size of std::string: " << sizeof(string) << endl;
	cout << "Size of Animal: " << sizeof(animal) << endl;
	cout << "Size of Cat: " << sizeof(cat) << endl;

	// Задание 1: Сделайте функцию say() виртуальной
	// Как, при этом, изменится размер классов?




	Animal* panimal = new Cat("Tomas", 8, 1);
	panimal->say();

	// Задание 2:
	// panimal это просто указатель на Animal. Откуда он знает, что нужно вызвать функцию из класса Cat?
}