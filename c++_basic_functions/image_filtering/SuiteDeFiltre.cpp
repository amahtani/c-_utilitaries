/******************************** TP numéro 1 de c++ : Ankur MAHTANI & Bastien PESAMOSCA - Exercice 2 ********************************/

#include <iostream>
#include "Image.hpp"
#include "Filtre.hpp"
#include "FiltreAddition.hpp"
#include <fstream>
#include <stdexcept>
#include <string>
#include <cassert>
#include <stdlib.h>
#include "FiltreMoyenne.hpp"
#include "SuiteDeFiltre.hpp"
#include <vector>

// constructeur
SuiteDeFiltre::SuiteDeFiltre()
{

}

// Methodes de la classe SuiteDeFiltre
void SuiteDeFiltre::apply(Image& i) const
{
	int j=0;

	for(j=0; j<liste.size(); j++)
	{
		liste[j]->apply(i); 
	}
}

void SuiteDeFiltre::add(Filtre* f)
{
	liste.push_back(f);
}