#include "Vecteur.hpp"


template <typename T>  // produit scalaire
int Vecteur<T>::produitScalaire(const Vecteur<T>& V)
{
	T somme=0;

	try
	{
		if ( !(V.nombreLigne==V->getNombreLigne()))
		{
			throw string("nombre de ligne incompatible");
		}
		else 
		{
			T result = 0;
			int i = 0; 
			for(i; i<V.nombreLigne;i++)
			{
				somme+=this->get(i,0)*V.get(i,0);
			}
			return somme;		
		}
	}
	catch(string const& chaine)
   	{
    	cerr << chaine << endl;
  	}
	
}





template <typename T>
Vecteur<T> Vecteur<T>::produitVectoriel(const Vecteur <T>& V){ // produit vectoriel seulement pour les vecteurs 3*1


	Vecteur<T> newVect(3);

	newVect.set(this->get(1,0)*V.get(2,0)-this->get(2,0)*V.get(1,0) , 0, 0);
	newVect.set(this->get(2,0)*V.get(0,0)-this->get(0,0)*V.get(2,0), 1 , 0);
	newVect.set(this->get(0,0)*V.get(1,0)-this->get(1,0)*V.get(0,0), 2, 0);
	return newVect;
}

template <typename T>
T Vecteur<T>::norme(){
	
	T norme=0;
	for(int i=0;i<this->getNombreLigne();i++)
		{
			//norme+=this->get(i,0)*get(i,0);
		}
	
	return sqrt(norme);
}

template <typename T>
T& Vecteur<T>::operator[](const int i) const{
	return (*this)(i,0);
}
