EXEC=binary

all: binary


binary: binary.o 
		gcc -o binary -g binary.o 



binary.o: binary.c
		gcc -o binary.o -g -c binary.c -Wall


clean :
	rm *.o 	
