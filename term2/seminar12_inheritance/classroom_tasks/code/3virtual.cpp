#include <iostream>
#include <string>

using namespace std;

// Базовый класс
class Animal
{
protected:
	std::string name;
public:
	Animal(std::string name) : name(name)
	{
	}

	virtual void say(const std::string& phrase)
	{
		cout << "<abstract sounds> " << phrase << " <abstract sounds>" << endl;
	}

	void tellPoem()
	{
		say("The lonely sail is showing white");
		say("Among the haze of the blue sea!..");
		say("What does it search in foreign part?");
		say("What left it in the native land?..");
	}
};

// Класс, который наследуется от Animal
class Cat : public Animal
{
private:
	int numberOfMouseCaught;
public:
	// Конструктор Cat вызывает конструктор Animal
	Cat(std::string name, int x) : Animal(name), numberOfMouseCaught(x)
	{
	}

	void say(const std::string& phrase)
	{
		cout << "Meow " << phrase  << " Meow. " << endl; 
	}

	void mouse_caught()
	{
		numberOfMouseCaught++;
	}
};

int main()
{
	Animal abstract("None");
	Cat murka("Murka", 5);

	
	// Что напечатает следующие строки:
	cout << "Abstract:" << endl;
	abstract.tellPoem();

	
	// Что напечатают следующие строки:
	cout << "Cat:" << endl;
	murka.tellPoem();


	// Как нужно изменить программу, чтобы класс ребёнок вызывал нужный метод say

}