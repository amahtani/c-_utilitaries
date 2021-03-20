/******************************** TP numéro 1 de c++ : Ankur MAHTANI & Bastien PESAMOSCA - Exercice 2 ********************************/

// Creation de la classe FiltreAddition qui herite de la classe abstraite Filtre

#include <string>

#ifndef FILTREADDITION_HPP
#define FILTREADDITION_HPP

class FiltreAddition : public Filtre
{
public:
 	
 	//constructeur
	FiltreAddition(int val);

	//methode
	void apply(Image& i) const;
	

private:

	//attribut
	int valeur;
	
};

#endif