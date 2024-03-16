path = ../../../3rdparty/SFML-2.5.1
name1 = testing_font_stack
name2 = testing_font_heap


default: testing_font_stack testing_font_heap

testing_font_stack:
	g++ ./testing_font_stack.cpp -std=c++11 -o testing_font_stack.exe -I $(path)/include -L $(path)/lib -lsfml-graphics -lsfml-window -lsfml-system 


testing_font_heap:
	g++ ./testing_font_heap.cpp -std=c++11 -o testing_font_heap.exe -I $(path)/include -L $(path)/lib -lsfml-graphics -lsfml-window -lsfml-system 