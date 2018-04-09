
all: arkanoid.o
	g++ -std=c++11 arkanoid.cpp -o arkanoid -lsfml-graphics -lsfml-window -lsfml-system
	rm ./arkanoid.o

arkanoid.o: arkanoid.cpp
	g++ -c arkanoid.cpp
