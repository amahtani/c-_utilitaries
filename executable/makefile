EXEC=main

all: main

main: main.o
		g++ -o  main main.o

main.o: main.cpp
		g++ -cpp main.cpp -Wall

clean :
	rm *.o 	