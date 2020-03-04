main: main.o image.o
	g++ -o main.exe main.o image.o

main.o:
	g++ -c main.cpp

image.o:
	g++ -c image.cpp

clear:
	rm main.o
	rm image.o
	rm main.exe