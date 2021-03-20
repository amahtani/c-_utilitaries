EXEC=client

all: serveur client


serveur: serveur.o 
		gcc -o serveur -g serveur.o 


client: client.o 
		gcc -o client -g client.o 


serveur.o: serveur.c
		gcc -o serveur.o -g -c serveur.c -Wall
		
client.o: client.c
		gcc -o client.o -g -c client.c -Wall


clean :
	rm *.o 	
