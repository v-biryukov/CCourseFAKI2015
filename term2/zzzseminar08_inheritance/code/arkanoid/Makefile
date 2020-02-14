
all: arkanoid.o
	g++ arkanoid.cpp -o arkanoid -lsfml-graphics -lsfml-window -lsfml-system
	rm ./arkanoid.o

arkanoid.o: arkanoid.cpp
	g++ -c arkanoid.cpp
