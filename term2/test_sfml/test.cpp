#include <iostream>
using namespace std;

class PlayerStateMachine;

class PlayerState
{
public:
    virtual void jump(PlayerStateMachine* sm) = 0;
    virtual void start_running(PlayerStateMachine* sm) = 0;
    virtual void stop(PlayerStateMachine* sm) = 0;
    virtual void start_sliding(PlayerStateMachine* sm) = 0;
    virtual void hook(PlayerStateMachine* sm) = 0;
    void attacked(PlayerStateMachine* sm);
    virtual void print() = 0;
    virtual ~PlayerState() {};
};

class Idle : public PlayerState
{
    void jump(PlayerStateMachine* sm);
    void start_running(PlayerStateMachine* sm);
    void stop(PlayerStateMachine* sm) {}
    void start_sliding(PlayerStateMachine* sm) {}
    void hook(PlayerStateMachine* sm) {}
    void print();
};
class Running : public PlayerState
{
    void jump(PlayerStateMachine* sm);
    void start_running(PlayerStateMachine* sm) {}
    void stop(PlayerStateMachine* sm);
    void start_sliding(PlayerStateMachine* sm);
    void hook(PlayerStateMachine* sm) {}
    void print();
};
class Jumping : public PlayerState
{
    void jump(PlayerStateMachine* sm) {}
    void start_running(PlayerStateMachine* sm);
    void stop(PlayerStateMachine* sm);
    void start_sliding(PlayerStateMachine* sm) {}
    void hook(PlayerStateMachine* sm);
    void print();
};
class Sliding : public PlayerState
{
    void jump(PlayerStateMachine* sm);
    void start_running(PlayerStateMachine* sm);
    void stop(PlayerStateMachine* sm) {}
    void start_sliding(PlayerStateMachine* sm) {}
    void hook(PlayerStateMachine* sm) {}
    void print();
};
class Hooked : public PlayerState
{
    void jump(PlayerStateMachine* sm);
    void start_running(PlayerStateMachine* sm) {}
    void stop(PlayerStateMachine* sm) {}
    void start_sliding(PlayerStateMachine* sm) {}
    void hook(PlayerStateMachine* sm) {}
    void print();
};
class Dead : public PlayerState
{
    void jump(PlayerStateMachine* sm) {}
    void start_running(PlayerStateMachine* sm) {}
    void stop(PlayerStateMachine* sm) {}
    void start_sliding(PlayerStateMachine* sm) {}
    void hook(PlayerStateMachine* sm) {}
    void print();
};

class PlayerStateMachine
{
private:
    PlayerState* state;
public:
    PlayerStateMachine()
    {
        state = new Idle();
    }
    void set_state(PlayerState* new_state)
    {
        delete state;
        state = new_state;
    }
    void jump()
    {
        state->jump(this);
    }
    void start_running()
    {
        state->start_running(this);
    }
    void stop()
    {
        state->stop(this);
    }
    void start_sliding()
    {
        state->start_sliding(this);
    }
    void hook()
    {
        state->hook(this);
    }
    void attacked()
    {
        state->attacked(this);
    }
    void print_state()
    {
        state->print();
    }
    ~PlayerStateMachine()
    {
        delete state;
    }
};

void PlayerState::attacked(PlayerStateMachine* sm)
{
    sm->set_state(new Dead());
}

void Idle::print()
{
    cout << "idle" << endl;
}
void Running::print()
{
    cout << "running" << endl;
}
void Sliding::print()
{
    cout << "sliding" << endl;
}
void Hooked::print()
{
    cout << "hooked" << endl;
}
void Jumping::print()
{
    cout << "jumping" << endl;
}
void Dead::print()
{
    cout << "dead" << endl;
}

void Idle::jump(PlayerStateMachine* sm)
{
    sm->set_state(new Jumping());
}
void Idle::start_running(PlayerStateMachine* sm)
{
    sm->set_state(new Running());
}

void Running::jump(PlayerStateMachine* sm)
{
    sm->set_state(new Jumping());
}
void Running::stop(PlayerStateMachine* sm)
{
    sm->set_state(new Idle());
}
void Running::start_sliding(PlayerStateMachine* sm)
{
    sm->set_state(new Sliding());
}

void Jumping::stop(PlayerStateMachine* sm)
{
    sm->set_state(new Idle());
}
void Jumping::hook(PlayerStateMachine* sm)
{
    sm->set_state(new Hooked());
}
void Jumping::start_running(PlayerStateMachine* sm)
{
    sm->set_state(new Running());
}

void Sliding::jump(PlayerStateMachine* sm)
{
    sm->set_state(new Jumping());
}
void Sliding::start_running(PlayerStateMachine* sm)
{
    sm->set_state(new Running());
}

void Hooked::jump(PlayerStateMachine* sm)
{
    sm->set_state(new Jumping());
}


int main()
{
    PlayerStateMachine sm;
    sm.print_state();
    sm.jump();
    sm.print_state();
    sm.hook();
    sm.print_state();
    sm.start_running();
    sm.print_state();
    sm.jump();
    sm.print_state();
    sm.stop();
    sm.print_state();
    sm.attacked();
    sm.print_state();
    sm.stop();
    sm.print_state();
}