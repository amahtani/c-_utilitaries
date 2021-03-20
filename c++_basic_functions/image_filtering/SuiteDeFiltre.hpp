/******************************** TP numéro 1 de c++ : Ankur MAHTANI & Bastien PESAMOSCA - Exercice 2 ********************************/

#include <string>
#include <vector>

#ifndef SUITEDEFILTRE_HPP
#define SUITEDEFILTRE_HPP


// Definition de la classe SuiteDeFiltre qui herite de la classe Filtre
class SuiteDeFiltre : public Filtre
{
public:
 	
 	//constructeur
	SuiteDeFiltre();

	//methodes
	void add(Filtre* f);
	void apply(Image& i) const;
	

private:

	std::vector<Filtre*> liste;		
};

#endif