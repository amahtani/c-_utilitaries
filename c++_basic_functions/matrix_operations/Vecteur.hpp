#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include "Matrice.hpp"


template <typename T>
class Vecteur : public Matrice<T> {  // provient de la classe matrice

public:
	

	//constructeurs
	Vecteur(int nombreLigne): Matrice<T>(nombreLigne,1){} 
	

	//méthodes

	int produitScalaire(const Vecteur<T>& vect); // produit scalaire entre deux vecteurs
	Vecteur<T> produitVectoriel(const Vecteur<T>& vect); // produit vectoriel entre 2 vecteurs
	T norme(); // norme d'un vecteur
	T& operator[](const int i) const; // accès en lecture et en écriture à l'élément vec[i]

};


#endif
