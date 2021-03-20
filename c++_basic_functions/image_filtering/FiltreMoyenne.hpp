/******************************** TP numéro 1 de c++ : Ankur MAHTANI & Bastien PESAMOSCA - Exercice 2 ********************************/

#include <string>

#ifndef FILTREMOYENNE_HPP
#define FILTREMOYENNE_HPP


// Creation de la classe FiltreMoyenne qui herite de la classe abstraite Filtre
class FiltreMoyenne : public Filtre
{
public:
 	
 	//constructeur
	FiltreMoyenne(int taille_filtre);

	//methode
	void apply(Image& i) const;
	

private:

	//attribut
	int n;

		
};



#endif