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
protected:
	float swimming_speed;
public:
	// Конструктор Fish вызывает конструктор Animal
	Fish(std::string name, int age, float swimming_speed) : Animal(name, age), swimming_speed(swimming_speed)
	{
	}

	void say()
	{
		cout << "Glub glub glub! My name is " << name <<". I am " << age << " old. "; 
		cout << "My swimming_speed = " << swimming_speed << endl;
	}
};

// Класс, который наследуется от Animal
class WildFish : public Fish
{
private:
	std::string origin;
public:
	// Конструктор WildFish вызывает конструктор Fish
	WildFish(std::string name, int age, float swimming_speed, std::string origin) 
		: Fish(name, age, swimming_speed), origin(origin)
	{
	}

	void say()
	{
		cout << "Glub glub glub! I am wild fish " << name <<" and I am " << age << " old."; 
		cout << " My swimming_speed is " << swimming_speed;
		cout << " My origin is " << origin << endl;
	}
};


struct Color
{
	unsigned char r, g, b;
};

// Класс, который наследуется от Fish
class AquariumFish : public Fish
{
private:
	Color color;
public:
	// Конструктор WildFish вызывает конструктор Fish
	AquariumFish(std::string name, int age, float swimming_speed, Color color) 
		: Fish(name, age, swimming_speed), color(color)
	{
	}

	void say()
	{
		cout << "Glub glub glub! I am aquarium fish " << name <<" and I am " << age << " old."; 
		cout << " My swimming_speed is " << swimming_speed;
		cout << " My color is (" << (int)color.r << ", " << (int)color.g << ", " << (int)color.b << ")" << endl;
	}
};

int main()
{
	// Обратите внимание, что функция say() класса Fish не отмечена как виртуальная
	// Задание 1: Что напечатает следующий код:

	Animal* panimal = new AquariumFish("Nemo", 11, 65.5, {50, 100, 200});
	panimal->say();

	Fish* pfish = new AquariumFish("Nemo", 11, 65.5, {50, 100, 200});
	pfish->say();

}