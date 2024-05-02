CC=g++

gradient_descent.o: gradient_descent.h gradient_descent.cpp
	$(CC) -Wall -c gradient_descent.cpp

main.o: main.cpp
	$(CC) -Wall -c main.cpp 

main: gradient_descent.o main.o
	$(CC) -Wall -o main doctest.h gradient_descent.o main.o