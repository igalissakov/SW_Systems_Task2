CC=gcc
AR=ar 
FLAGS= -Wall -g
.PHONY: all

all: lib.a main.o
	$(CC) $(FLAGS) -o connections main.o my_mat.o

connections: lib.a main.o
	$(CC) $(FLAGS) -o main.o my_mat.o connections
lib.a: my_mat.o
	$(AR) rcs -o lib.a my_mat.o
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c
main.o: my_mat.h main.c
	$(CC) $(FLAGS) -c main.c
clean:
	rm -f *.o *.a *.so *.out