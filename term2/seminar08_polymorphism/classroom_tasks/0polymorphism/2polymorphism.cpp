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


// Класс, который наследуется от Animal
class Dog : public Animal
{
private:
	float barking_power;
public:
	// Конструктор Dog вызывает конструктор Animal
	Dog(std::string name, int age, float barking_power) : Animal(name, age), barking_power(barking_power)
	{
	}

	void say()
	{
		cout << "Woof! My name is " << name <<". I am " << age << " old. "; 
		cout << "My barking power = " << barking_power << endl;
	}
};


// Класс, который наследуется от Animal
class Fish : public Animal
{
private:
	float swimming_speed;
public:
	// Конструктор Dog вызывает конструктор Animal
	Fish(std::string name, int age, float swimming_speed) : Animal(name, age), swimming_speed(swimming_speed)
	{
	}

	void say()
	{
		cout << "Glub glub glub! My name is " << name <<". I am " << age << " old. "; 
		cout << "My swimming_speed = " << swimming_speed << endl;
	}
};

int main()
{
	// Создаём массив из указателей
	Animal* animals[5];
	animals[0] = new Cat("Murka", 10, 777);
	animals[1] = new Animal("None", 97);
	animals[2] = new Fish("Nemo", 5, 9.5);
	animals[3] = new Fish("Finley", 4, 7.5);
	animals[4] = new Dog("Oscar", 11, 65.5);

	// Благодаря полиморфизму для каждого указателя будет вызываться своя функция say
	for (int i = 0; i < 5; i++)
	{
		animals[i]->say();
	}

	// Задание 1: Скомпилируйте и запустите
	// На самом деле этот код работает не совсем правильно
	// Он всегда вызывает функцию say из класса Animal
	// Измените его так, чтобы он всегда вызывал правильную функцию say


	// Задание 2: Измените массив на std::vector

	// Задание 3: Не забывайте, что всё выделенное с помощью new нужно удалить
	// Освободите память, используя delete
}