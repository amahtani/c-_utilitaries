/******************************** TP numéro 4 : Ankur MAHTANI & Bastien PESAMOSCA - Exercice 2 ********************************/

#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


#define t 11 //taille d'un buffer pouvant contenir les caractères "Hello OK!\n"

int main()  //Programme qui permet la communication entre 2 processus père et fils via 2 pipes anonymes
{	

	//déclaration des variables
	int r; 
	int desc[2]; // initialisation du descripteur du tube 1
	int desc2[2]; // initialisation du descripteur du tube 2 
	char* hello = "Hello !\n"; //initialisation de la chaine de caractère envoyé par le père
	char* hello_pere = "Hello OK!\n"; //initialisation de la chaine de caractère envoyé par le fils
	int pid,i; //initialisation de la variable du processus fils et d'un compteur i 
	const char buf[t]; //


	if(pipe(desc)) //si cette valeur est différente de 0, le pipe n'a pas été créé
	{
		perror("Echec de création du pipe");
		return(1); //fin du programme en cas d'échec de création d'un pipe
	}
	
	if(pipe(desc2))  //si cette valeur est différente de 0, le pipe n'a pas été créé
	{
		perror("Echec de création du pipe");
		return(1);  //fin du programme en cas d'échec de création d'un pipe
	}
	

	pid = fork(); //on créé un processus fils

	if (pid == 0)   //si le fils est bien créé, pid = 0, sinon pid=-1
	{	
		close(desc[1]); //on ferme l'écriture du premier tube
		close(desc2[0]); //on ferme la lecture du deuxième tube  
		for(i=0;i<3;i++){  //itération 3 fois pour répéter la séquence 3 fois

			read(desc[0], &buf, strlen(hello));  //on lit une séquence de caractère du tube 1 de longueur "Hello !\n"
			if(strcmp(buf, "Hello !\n") == 0) {  //si cette séquence est bien "Hello !\", on peut l'écrire dans le tube 2 
				printf("%s",buf); //on affiche la séquence qui va être copié dans le tube 2
				write(desc2[1],hello_pere, strlen(hello_pere));  //on écrit la séquence hello_père "Hello OK!\n" 
			}
		}
	}
	

	else  //quand on est dans le processus père

	{	close(desc[0]); // on ferme la lecture du premier tube
		close(desc2[1]); // on ferme l'écriture du deuxième tube
		for(i=0;i<3;i++){  //3 itérations pour répéter 3 fois la séquence		
				  
				write(desc[1],hello, strlen(hello)); //on écrit la séquence hello "Hello !\n" dans le premier tube

				read(desc2[0], &buf, strlen(hello_pere)); //on lit une séquence de caractère du tube 2 de longueur "Hello OK!\n"

				if(strcmp(buf, "Hello OK!\n") == 0) { //si la séquence lue dans le tube 2 est bien "Hello OK!\n"
					printf("%s",buf);   //on l'affiche
				}			            
		}
	}
return 0;
}

