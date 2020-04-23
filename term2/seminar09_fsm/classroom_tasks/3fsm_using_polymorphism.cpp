#include <iostream>

using namespace std;

// Конечный автомат (Finite State Machine - FSM)
// Реализация на основе полиморфизма


/*
Абстрактный метод:
	виртуальный метод, который не определён (но должен быть определён в классах-наследниках)
	обозначается, с помощью присваивания нулю виртуальной функции, например:
	virtual void open(DoorStateMachine* sm) = 0;

Абстрактный класс:
	класс, который содержит хотя бы один абстрактный метод
	Экземпляры такого класса нельзя создать (но можно от него наследоваться)

Интерфейс:
	класс, у которого все методы абстрактные
*/

// Интерфейс DoorState
class DoorState
{
public:
	virtual void open(DoorStateMachine* sm) = 0;
	virtual void close(DoorStateMachine* sm) = 0;
	virtual void lock(DoorStateMachine* sm) = 0;
	virtual void unlock(DoorStateMachine* sm) = 0;
	virtual void print() = 0;
	virtual ~DoorState(){};
};

class Open : public DoorState
{
	void open(DoorStateMachine* sm) {}
	void close(DoorStateMachine* sm)
	{
		sm->set_state(new Closed());
	}
	void lock(DoorStateMachine* sm) {}
	void unlock(DoorStateMachine* sm) {}
	void print()
	{
		cout << "It's open!" << endl;
	}
};

class Closed : public DoorState
{
	void open(DoorStateMachine* sm)
	{
		sm->set_state(new Open());
	}
	void close(DoorStateMachine* sm) {}
	void lock(DoorStateMachine* sm)
	{
		sm->set_state(new Locked());
	}
	void unlock(DoorStateMachine* sm) {}
	void print()
	{
		cout << "It's closed!" << endl;
	}
};

class Locked : public DoorState
{
	void open(DoorStateMachine* sm) {}
	void close(DoorStateMachine* sm) {}
	void lock(DoorStateMachine* sm) {}
	void unlock(DoorStateMachine* sm) 
	{
		sm->set_state(new Closed());
	}
	void print()
	{
		cout << "It's locked!" << endl;
	}
};


class DoorStateMachine
{
private:
	DoorState* state;

public:

	DoorStateMachine()
	{
		state = new Closed();
	}

	void set_state(DoorState* new_state)
	{
		delete state;
		state = new_state;
	}

	void open() 
	{
		state->open(this);
	}
	void close()
	{
		state->close(this);
	}
	void lock()
	{
		state->lock(this);
	}
	void unlock()
	{
		state->unlock(this);
	}

	void print_state()
	{
		state->print();
	}

	~DoorStateMachine()
	{
		delete state;
	}
};


int main()
{
	// Скомпилировать эту программу не получится
	// Так как нужно разделить описание классов и реализацию (см. следующий файл)
	DoorStateMachine sm;
	sm->print_state();
	sm->open();
	sm->print_state();
}
