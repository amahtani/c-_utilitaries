#include "Vecteur.hpp"


void Vecteur::affiche()
{
	cout << "x = " << x << " y = " << y << "\n";
}


float Vecteur::norme()
{
	return pow(pow(x,2)+pow(y,2),1/2);
}

Vecteur* Vecteur::addition(Vecteur vecteur)
{
	Vecteur* vec = new Vecteur(vecteur.x+x, vecteur.y+y);
	return vec;
}