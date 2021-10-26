path = ../../3rdparty/SFML-2.5.1

all: 0enums 1enums 2fsm 4fsm_using_polymorphism 5player_animations 6player_states

0enums:
	gcc ./0enums.c -std=c99 -o 0enums

1enums:
	g++ ./1enums.cpp -std=c++11 -o 1enums

2fsm.cpp:
	g++ ./2fsm.cpp.cpp -std=c++11 -o 2fsm.cpp

4fsm_using_polymorphism.cpp:
	g++ ./4fsm_using_polymorphism.cpp.cpp -std=c++11 -o 4fsm_using_polymorphism.cpp

5player_animations:
	g++ ./5player_animations.cpp -std=c++11 -o 5player_animations -I $(path)/include -L $(path)/lib/ -lsfml-graphics -lsfml-window -lsfml-system 

6player_states:
	g++ ./6player_states.cpp -std=c++11 -o 6player_states -I $(path)/include -L $(path)/lib/ -lsfml-graphics -lsfml-window -lsfml-system 

clear:
	rm ./*.exe