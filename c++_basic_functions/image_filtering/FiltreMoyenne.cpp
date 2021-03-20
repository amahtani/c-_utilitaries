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

// Methodes de la classe FiltreMoyenne

FiltreMoyenne::FiltreMoyenne(int taille_filtre)
{
	nom = "Filtre Moyenne";

	n = taille_filtre;
}

void FiltreMoyenne::apply(Image& i) const
{
	int lim = n/2; //n = taille du filtre 
	int somme = 0;

	for(int j= lim ; j<= i.get_h() - lim; j++)
	{
		for(int k= lim ; k<= i.get_w() - lim; k++)
		{
			// pour chaque pixel on va regarder ses voisins 
			for(int l= j-lim ; l<= j+lim ; l++ )
			{
				for(int m= k-lim ; m<= k+lim ; m++)
				{
					somme = somme + i.get(l,m);  //on fait la somme de chaque pixels voisins
				}
			}
			i.set(j,k,somme/(n*n)); //on remplace la valeur du pixel courant par la moyenne de tous ses voisins
			somme = 0 ;
		}
	}
}