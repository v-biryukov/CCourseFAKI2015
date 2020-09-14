#include <iostream>

using namespace std;

class DoorStateMachine;

class DoorState
{
public:
	virtual void open(DoorStateMachine* sm) = 0;
	virtual void close(DoorStateMachine* sm) = 0;
	virtual void lock(DoorStateMachine* sm) = 0;
	virtual void unlock(DoorStateMachine* sm) = 0;
	virtual void print() = 0;
	virtual ~DoorState() {};
};

class Open : public DoorState
{
	void open(DoorStateMachine* sm) {}
	void close(DoorStateMachine* sm);
	void lock(DoorStateMachine* sm) {}
	void unlock(DoorStateMachine* sm) {}
	void print();
};

class Closed : public DoorState
{
	void open(DoorStateMachine* sm);
	void close(DoorStateMachine* sm) {}
	void lock(DoorStateMachine* sm);
	void unlock(DoorStateMachine* sm) {}
	void print();
};

class Locked : public DoorState
{
	void open(DoorStateMachine* sm) {}
	void close(DoorStateMachine* sm) {}
	void lock(DoorStateMachine* sm) {}
	void unlock(DoorStateMachine* sm);
	void print();
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


void Open::close(DoorStateMachine* sm)
{
	sm->set_state(new Closed());
}

void Open::print()
{
	cout << "It's open!" << endl;
}

void Closed::open(DoorStateMachine* sm)
{
	sm->set_state(new Open());
}

void Closed::lock(DoorStateMachine* sm)
{
	sm->set_state(new Locked());
}

void Closed::print()
{
	cout << "It's closed!" << endl;
}

void Locked::unlock(DoorStateMachine* sm) 
{
	sm->set_state(new Closed());
}
void Locked::print()
{
	cout << "It's locked!" << endl;
}


int main()
{
	DoorStateMachine sm;
	// В начале дверь закрыта (Closed)
	sm.print_state();

	// Откроем её
	sm.open();
	sm.print_state();

	// Попытаемся открыть ещё, состояние от этого не должно поменяться
	sm.open();
	sm.open();
	sm.print_state();

	// Попытаемся запереть на ключ открытую дверь (ничего не получится)
	sm.lock();
	sm.print_state();

	// Много разных операций, приводящие к тому, что дверь будет заперта на ключ
	sm.close();
	sm.lock();
	sm.unlock();
	sm.open();
	sm.close();
	sm.close();
	sm.lock();
	sm.print_state();
}

/* Задание:
	Создайте аналогичный конечный автомат для персонажа компьютерной игры.
	Состояния:
		Idle, Running, Jumping, Sliding (скользит по полу), Hooked (зацепился за уступ), Dead
	Действия:
		jump, start_running, stop (переход в Idle), start_sliding, hook, attacked 

		Схему автомата можно посмотреть в файле hero_fsm.png
*/