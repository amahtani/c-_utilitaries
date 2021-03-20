/******************************** TP numéro 1 de c++ : Ankur MAHTANI & Bastien PESAMOSCA - Exercice 2 ********************************/

// Methodes de la classe FiltreAddition
#include <iostream>
#include "Image.hpp"
#include "Filtre.hpp"
#include "FiltreAddition.hpp"
#include <fstream>
#include <stdexcept>
#include <string>
#include <cassert>
#include <stdlib.h>

FiltreAddition::FiltreAddition(int val)
{
	nom = "Filtre Addition";

	valeur = val;
}

void FiltreAddition::apply(Image& i) const
{

	int temp;

	for(int j=0; j<i.get_h(); j++)
	{
		for(int k=0; k<i.get_w(); k++)
		{
			// on ajoute a chaque pixel la valeur du meme pixel en rajoutant la constante que l on veut 
			temp = (int) i.get(j,k) + valeur;
			if( (int) temp < 0) temp = 0;
			if( (int) temp > 255) temp = 255;

			i.set(j,k,temp);
		}
		
	}
}