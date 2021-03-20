/******************************** TP numéro 2 : Ankur MAHTANI & Bastien PESAMOSCA - Exercice 2 ********************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#include "binary.h"
#include "img.h"



int main(int argc, char** argv){


	if (argc == 1) {
		printf("Pas de fichier en argument\n"); 
		return 0; //si on ne met pas de fichier en argument
	} 

	printf("%s\n",argv[1]); //affichage du nom du fichier que l'on vient d'envoyer


	FILE* fichier = fopen(argv[1],"r");
	if (fichier == NULL) {exit(0);} //si l'ouverture du fichier n'a pas fonctionné, on arrete immédaitemment le programme


	print_data(fichier); //on affiche les données utiles de l'entete de l'image tga

	img_t* img = (img_t*) malloc(sizeof(img_t));  //allocation de mémoire temporaire
	if (img == NULL) // si l'allocation a échoué
    	{exit(0);}// on arrête immédiatement le programme


	read_header(fichier,img); //lit l'entete contenu dans le fichier f et complete la structure vide img avec ces donnes 

	read_pixels(fichier, img); //fonction qui copie les pixels de f vers img

	write_ppm(argv[1],img);  //on convertit l'image tga en image ppm

	free(img);

	return 0;

}
