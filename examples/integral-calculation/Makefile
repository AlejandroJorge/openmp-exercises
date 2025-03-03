CC=gcc
FLAGS=-fopenmp -Wall -O3

bench: serial.out parallel.out
	./serial.out
	./parallel.out 1
	./parallel.out 2
	./parallel.out 4
	./parallel.out 8
	./parallel.out 16


serial.out: serial.c
	$(CC) $(FLAGS) serial.c -o serial.out

parallel.out: parallel.c
	$(CC) $(FLAGS) parallel.c -o parallel.out
