CC=gcc
FLAGS=-fopenmp -Wall -lm -O3

bench: bench-serial bench-parallel

bench-serial: serial.out
	./serial.out

bench-parallel: parallel.out
	./parallel.out 1
	./parallel.out 2
	./parallel.out 4
	./parallel.out 8
	./parallel.out 16

serial.out: serial.c
	$(CC) $(FLAGS) serial.c -o serial.out

parallel.out: parallel.c
	$(CC) $(FLAGS) parallel.c -o parallel.out
