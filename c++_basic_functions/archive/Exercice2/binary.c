/******************************** TP numéro 2 : Ankur MAHTANI & Bastien PESAMOSCA - Exercice 2 ********************************/


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "binary.h"




ui8_t read_ui8(FILE *f){ //lecture de 8 bits


		ui8_t p;	// on déclare une variable de 8 bits de type ui8_t qui recevra le nombre d'éléments renvoyé par fread
		fread(&p, sizeof(p), 1 ,f); // fread lit sizeof(p) éléments de données, chacun d'eux representant un octet de long se trouvant dans le fichier f, et en renvoie le nombre dans p
		return p;
			
}


ui16_t read_ui16(FILE *f){ //lecture de 16 bits

		
		ui16_t p;// on déclare une variable de 16 bits de type ui16_t qui recevra le nombre d'éléments renvoyé par fread	
		fread(&p, sizeof(p), 1 ,f);// fread lit sizeof(p) éléments de données, chacun d'eux representant 2 octets de long se trouvant dans le fichier f, et en renvoie le nombre dans p
		return p;
	

}


ui32_t read_ui32(FILE *f){ //lecture de 16 bits

		
		ui32_t p; // on déclare une variable de 32 bits de type ui32_t qui recevra le nombre d'éléments renvoyé par fread	
		fread(&p, sizeof(p), 1 ,f);// fread lit sizeof(p) éléments de données, chacun d'eux representant 4 octets de long se trouvant dans le fichier f, et en renvoie le nombre dans p
		return p;
	
	
}

ui32_t file_size(const char* fname){ // renvoie la taille en octets du fichier

		
	struct stat buffer;   // on créé un buffer de struct stat
	stat(fname,&buffer);  // on le remplit avec stat du fichier	
	ui32_t size = (ui32_t)(((buffer.st_size)+1) );  // on récupère la taille dans buffer.st_size
	return size;
	
}


//On peut utiliser ce main pour tester les fonctions de lecture de bits et 
/*int main(){

	FILE* fichier = fopen("image.tga","r");  // ouverture du fichier image

	printf("Taille du fichier image (octets) : %lu \n", file_size("image.tga"));   // execution et lecture file_size

	printf("Présence de idlength : %hhu \n", read_ui8(fichier));   // lecture des 8 premiers bits
	printf("Type de couleur : %us \n", read_ui16(fichier));			//lecture des des 16 bits suivants
	printf("%lu \n", read_ui32(fichier));							//lecture des 32 bits suivants
	
return 0;


}*/


