EXEC=main

all: main


main: binary.o main.o img.o
		gcc -o  main main.o binary.o img.o

img.o: img.c
		gcc -c img.c -Wall

main.o: main.c
		gcc -c main.c -Wall

binary.o: binary.c
		gcc -c binary.c -Wall


clean :
	rm *.o 	
