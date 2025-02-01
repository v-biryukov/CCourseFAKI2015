libpath = ../../../3rdparty/SFML-2.5.1

default: single_button four_buttons

single_button:
	g++ ./single_button.cpp -std=c++17 -o single_button.exe -I $(libpath)/include -L $(libpath)/lib/ -lsfml-graphics -lsfml-window -lsfml-system 

four_buttons:
	g++ ./four_buttons.cpp -std=c++17 -o four_buttons.exe -I $(libpath)/include -L $(libpath)/lib/ -lsfml-graphics -lsfml-window -lsfml-system 
