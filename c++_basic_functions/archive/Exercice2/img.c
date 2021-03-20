/******************************** TP numéro 2 : Ankur MAHTANI & Bastien PESAMOSCA - Exercice 2 ********************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#include "binary.h"
#include "img.h"


void read_header(FILE* f, img_t *img){ //lit l'entete contenu dans le fichier f et complete la structure vide img avec ces donnes 


	img->idlength = read_ui8(f); //on affecte à img->idlength la lecture des 8 premiers bits
	img -> colour_map_type = read_ui8(f); //on lit les 8 bits suivants 
	read_ui8(f);
	read_ui16(f); //on lit ici 16 bits mais on ne les "sauvegarde" pas
	img -> colour_map_length = read_ui16(f);
	img -> colour_map_depth = read_ui8(f);
	read_ui16(f);
	read_ui16(f);
	img -> width = read_ui16(f);
	img -> height = read_ui16(f);
	img -> bpp = read_ui8(f);
	read_ui8(f);



}



void print_data(FILE* f){  //affiche le nom du fichier, sa taille, sa taille en pixels, son nombre de bits par pixels
	

	img_t* img = (img_t*) malloc(sizeof(img_t)); //on alloue la mémoire nécessaire pour la création d'une image temporaire
	if (img == NULL) // si l'allocation a échoué
    	{ exit(0); }// on arrête immédiatement le programme


	read_header(f, img); //on affecte l'entete du fichier f à la structure img


	printf("La taille du fichier est : %lu octets\n", file_size("image.tga" )); //on affiche la taille du fichier que l'on récupère de la structure img
	printf("La taille de l'image est : %dx%d\n", img -> width, img -> height);  //on affiche la taille de l'image
	printf("Le nombre de bits par pixels est : %d bpp\n", img -> bpp);  //on affiche le nombre de bits par pixels

	free(img); //on libère la mémoire allouée à la structure temporaire img


}


ui32_t* get_pixel(const img_t* img, int row, int col){ // fonction qui permet de retourner un pixel en fonction de sa ligne et de sa colonne

	return &(img->pixels[(img-> width *row) + col ]);  
}



ui32_t make_pixel(ui8_t r, ui8_t g, ui8_t b){  // création d'un pixel sur 32 bits  à partir de ses nuances de rouge, vert , bleu codées sur  8 bits + 8 bits à 0

	ui32_t pix = 0; 
	pix = r;  // insertion des bits rouges

	pix <<= 8;  // décalage de 8 bits vers la gauche
	pix = pix | g; // insertion des bits verts 
	
	pix <<= 8;  // décalages de 8 bits vers la gauche
	pix = pix | b ; // insertion des 8 bits bleus

	//comme pix a été initialisé à 0, les bits restants (=les 8 derniers) seront à 0

	return pix;  	
   // au final, 8 bits rouges - 8 bits verts - 8 bits bleus - 8 bits à 0
	

}

void read_pixels(FILE* f, img_t* img){ //fonction qui copie les pixels de f vers img
	

	int test;
	test = fseek(f, (img->idlength)+((img->colour_map_type)*(img->colour_map_length)), SEEK_SET); //on avance dans le format de l'image jusqu'a la pixel data
	//on avance jusqu'au tableau des pixel data
	if (test != 0) {printf("Error"); //le fseek n'a pas fonctionné
	exit(0);} //on arrete le programme

	int nb_pix = (img->width)*(img->height); //nombre de pixels de l'image
	
	ui32_t* pix= malloc(nb_pix*sizeof(ui32_t)); // tableau temporaire contenant tous les pixels
	if (pix == NULL) // si l'allocation a échoué
    	{ exit(0); }// on arrête immédiatement le programme


	ui8_t b,g,r; //initialisation des bits de couleurs
	int i; //initialisation du compteur de pixels
	for(i=0; i<nb_pix+1;i++){ //on ne dépasse pas le nb de pixels de l'image
		
		b = read_ui8(f); //on lit dans l'ordre les 8 bits de la couleur bleue, puis vert et rouge
		g = read_ui8(f);
		r = read_ui8(f);
		read_ui8(f); //on lit les 8 bits suivants mais on ne les prend pas en compte pour la reproduction du pixel car ils sont nuls


		pix[i] =  make_pixel(b,g,r); //on créé un pixel à partir des données récupérées du fichier f
	}


	img->pixels = pix;  //le champs de pixels de img pointe vers pix


}


void write_ppm(const char* filename, const img_t* img){ //on convertit l'image tga en image ppm


	FILE* fichier = fopen("filename", "w"); //ouverture du fichier dans lequel on va écrire

	if (fichier == NULL) {exit(0);} //si l'ouverture du fichier n'a pas fonctionné, on arrete immédaitemment le programme

	fprintf(fichier,"P6\n"); //inscription des données de l'entete du fichier ppm
	fprintf(fichier,"%hu %hu \n", img->width, img->height); //dimensions de l'image
	fprintf(fichier,"255\n");


	int i, j; //initialisations des compteurs de pixels
	for(i=0; i<img->height; i++){ //parcours de l'image en hauteur
		for(j=0; j<img->width; j++){ //parcours de l'image en largeur
			fwrite(get_pixel(img, i, j), sizeof(ui32_t),1,fichier); //on récupère les pixels de img et on les copient dans le fichier filename donné en argument

		}
	}
}





