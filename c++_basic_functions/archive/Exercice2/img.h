/******************************** TP numéro 2 : Ankur MAHTANI & Bastien PESAMOSCA - Exercice 2 ********************************/

#ifndef _IMG_H
#define _IMG_H

#include "binary.h"




typedef struct img_t img_t;   //on définit un type structuré img_t

struct img_t

{
	
    ui8_t idlength;
	ui8_t colour_map_type;
	ui16_t colour_map_length;
	ui8_t colour_map_depth;
	ui16_t width;
	ui16_t height;
	ui8_t bpp; 
	ui32_t* pixels;


};

void read_header(FILE* f, img_t *img); // lit l'entête contenu dans le fichier f et complète la structure img_t
ui32_t* get_pixel(const img_t* img, int row, int col);  // fonction qui permet de retourner un pixel en fonction de sa ligne et de sa colonne
ui32_t make_pixel(ui8_t r, ui8_t g, ui8_t b);  // création d'un pixel sur 32 bits  à partir de ses nuances de rouge, vert , bleu codées sur  8 bits + 8 bits à 0
void read_pixels(FILE* f, img_t* img);  //fonction qui copie les pixels de f vers img
void write_ppm(const char* filename, const img_t* img);  //on convertit l'image tga en image ppm
void print_data(FILE* f);  //affiche le nom du fichier, sa taille, sa taille en pixels, son nombre de bits par pixels

#endif 
