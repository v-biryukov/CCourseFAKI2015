release: main.o vec.o
	gcc ./vec.o ./main.o -lm -o vecsum

vec.o: vec.c
	gcc -c ./vec.c;

main.o: main.c
	gcc -c ./main.c



clear:
	rm ./*.o
	rm ./vecsum
