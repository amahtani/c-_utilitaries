/******************************** TP numéro 1 de c++ : Ankur MAHTANI & Bastien PESAMOSCA - Exercice 2 ********************************/

#include <string>

#ifndef FILTRE_HPP
#define FILTRE_HPP

// Creation d'une classe Filtre
class Filtre
{
public:

	//methode abstraite
	virtual void apply(Image& i) const = 0;
	
	//accesseur
	const std::string& get_name() const;

protected:

	std::string nom;	
};



#endif