/******************************** TP numéro 1 de c++ : Ankur MAHTANI & Bastien PESAMOSCA - Exercice 2 ********************************/

#ifndef IMAGE_HPP
#define IMAGE_HPP

// Definition de la classe image
class Image
{
public:

	//constructeurs
	Image(const char* nom);
	Image(Image& i); 						// constructeur par copie 
	
	//methodes
	void load(const char* nom);
	void write(const char* nom);
	
	//accesseurs
	unsigned char get(int i, int j);
	void set(int i, int j, unsigned char valeur);
	int get_w();
	int get_h();


	//destructeur
	~Image();
	
	
private:
	//attributs
	int w; 									//largeur
	int h; 									//hauteur
	unsigned char* data; 					//données	
};

#endif