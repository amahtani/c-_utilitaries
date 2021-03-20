#ifndef MATRICE_HPP
#define MATRICE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <math.h>

using namespace std;

template<typename T>
class Matrice
{


private:
	T** t;//tableau de int, float ou double ou tout ce que tu veux , wallah essaie
	int nombreLigne;
	int nombreColonne;


public:
	
	
	// Constructeurs
	Matrice();
	Matrice(const int a, const int b);
	Matrice(const int a, const int b, const T** tab);
	Matrice(const Matrice<T>& MATTA);


	// Méthodes
	void afficher();  // affichage d'une matrice

	T& operator()(int a, int b); // accès en lecture et en écriture à la case t[a][b]
	const T& operator()(int a, int b) const; // lecture seule de la case t[a][b]
	Matrice<T>  operator=(const Matrice<T>& M);  // copie entre deux matrices
	Matrice<T> operator*(const Matrice<T>& M); //multiplication entre deux matrices
	Matrice<T> operator*(const T scalaire) const; // multiplication d'une matrice avec un scalaire
	Matrice<T> operator+(const  Matrice<T>& M); // addition de deux matrices
	Matrice<T>  operator+(const T valeur) const; // addition avec scalaire
	Matrice<T> operator-(const T valeur) const;  // soustraction avec constante
	Matrice<T> operator-(const  Matrice<T>& M); // soustraction de deux matrices
	bool operator==(Matrice<T> M); // comparaison de deux matrices
	//ostream& operator<<(ostream& ofs, Matrice<T>& M); // affiche la matrice dans un flux ostream
	
	//getters 
	const int getNombreLigne();
	const int getNombreColonne();
	T get(int i, int j) const;


	// setters
	void set(const int l,const int col,const T val);



	// destructeur
	~Matrice();

};


//________________________Constructeurs, setters, getters__________________________

template<typename T> 
T Matrice<T>::get(int i, int j) const{
	return *t[i*nombreColonne + j];
}

template <typename T>
Matrice<T>::Matrice() // constructeur par défaut
	{
		t = NULL;
		nombreLigne = 0;
		nombreColonne = 0; 
	}


template <typename T>
Matrice<T>::Matrice(const int a, const int b, const T** tab) // constructeur à partir d'un tableau et de ses propriétés
	{
		nombreLigne = a;
		nombreColonne = b;
		int i = 0;
		int j = 0;
		for(i;i<nombreLigne;i++)
		{
			for(j;j<nombreColonne;j++)
			{
				t[i][j] = tab[i][j];
			}
		}		
	}

template <typename T>
Matrice<T>::Matrice(const int a, const int b) // constructeurs à partir de deux entiers
	{

		nombreLigne = a;
		nombreColonne = b;

		t = new T*[nombreLigne];
		int c;
		for(c=0;c<=nombreLigne;c++)
		{
			t[c] = new T[nombreColonne];
		}

	}

template <typename T>
Matrice<T>::Matrice(const Matrice<T>& MATTA) // constructeur à partir d'une matrice 
	{
		
		nombreLigne = MATTA.nombreLigne;
		nombreColonne = MATTA.nombreColonne;
	

		int A;
		int B;
		T c;
		//T** c = new *T[nombreLigne*nombreColonne];
		for(A=0;A<nombreLigne;A++)
		{
			for(B=0;B<nombreColonne;B++)
			{
				c = MATTA(A,B);
				t[A][B] = c;
			}
		}

	}






template<typename T> // setter
void Matrice<T>::set(const int l,const int col,const T val)
{
	t[l][col]=val;
} 




template<typename T> // retourne le nombre de lignes
const int Matrice<T>::getNombreLigne()
{
	return nombreLigne;
}

template<typename T> // retourne le nombre de colonne
const int Matrice<T>::getNombreColonne()
{
	return nombreColonne;
}


//________________________Operateurs__________________________

template <typename T> // operateur + avec une constante
Matrice<T> Matrice<T>::operator+(const T valeur) const
{
	int i =0;
	int j =0;
	Matrice<T> newMat(nombreLigne,nombreColonne);
	for (i; i<nombreLigne; i++)
	{
		for (j; j<nombreColonne; j++)
		{
			newMat.set(i,j,t[i][j]+valeur);
		}
	}
	return newMat;
}

template<typename T> // operateur + entre 2 matrices
Matrice<T> Matrice<T>::operator+(const  Matrice<T>& M)
{
	try
	{
		if (!(nombreColonne == M.nombreColonne) || !(nombreLigne==M.nombreLigne))
		{
			throw string("nombre de ligne ou de colonne incompatible");
		}
		else 
		{
			Matrice<T>  newMat(nombreLigne,nombreColonne); // nouvelle matrice
			for(int i=0; i<nombreLigne;i++)
			{
				for(int j=0; j<nombreColonne; j++)
				{
					newMat.set(i,j,t[j][i]+ M.t[i][j]);
				}
			}
			return newMat;		
		}
	}
	catch(string const& chaine)
   	{
    	cerr << chaine << endl;
  	}
}

template <typename T> // opérateur - avec une constante
Matrice<T> Matrice<T>::operator-(const T valeur) const
{
	int i =0;
	int j =0;
	Matrice<T> newMat(nombreLigne,nombreColonne);
	for (i; i<nombreLigne; i++)
	{
		for (j; j<nombreColonne; j++)
		{
			newMat.set(i,j,t[i][j]-valeur);
		}
	}
	return newMat;
}




template<typename T> // opérateur - entre 2 matrices
Matrice<T> Matrice<T>::operator-(const  Matrice<T>& M)
{
	try
	{
		if (!(nombreColonne == M.nombreColonne) || !(nombreLigne==M.nombreLigne))
		{
			throw string("nombre de ligne ou de colonne incompatible");
		}
		else 
		{
			Matrice<T>  newMat(nombreLigne,nombreColonne); // nouvelle matrice
			for(int i=0; i<nombreLigne;i++)
			{
				for(int j=0; j<nombreColonne; j++)
				{
					newMat.set(j,i,t[j][i]- M.t[i][j]);
				}
			}
			return newMat;		
		}
	}
	catch(string const& chaine)
   	{
    	cerr << chaine << endl;
  	}
}


template<typename T>
T& Matrice<T>::operator()(int a, int b) //lecture et écriture d'une matrice
{				
	return t[a][b];
}


template<typename T>
const T& Matrice<T>::operator()(int a, int b) const // lecture seule de const Matrice
{
	return t[a][b];
}


template<typename T> // operateur = entre 2 matrices
Matrice<T> Matrice<T>::operator=(const Matrice<T>& M){

try
	{
		if (!(nombreColonne == M.nombreColonne) || !(nombreLigne==M.nombreLigne))
		{
			throw string("nombre de ligne ou de colonne incompatible");
		}
		else 
		{
			for(int i=0; i<nombreLigne;i++)
			{
				for(int j=0; j<nombreColonne; j++)
				{
					t[i][j] = M(i,j);
				}
			}
			return *this ;
		}
	}

	catch(string const& chaine)
   	{
    	cerr << chaine << endl;
  	}
	

}

template<typename T> 
Matrice<T> Matrice<T>::operator*(const T scalaire)	const				// operateur * avec un scalaire
{
	Matrice<T> res(*this);
	for(int i=0; i<nombreLigne; i++)
	{
		for(int j=0; j<nombreColonne; j++)
		{
			res.t[i][j] = res.t[i][j]*scalaire;
		}
	}
	return res;	
}



template<typename T>
Matrice<T> Matrice<T>::operator*(const Matrice<T>& M){ // operateur multiplication avec 2 matrices


try
	{
		if (!(nombreColonne == M.nombreColonne) || !(nombreLigne == M.nombreLigne))
		{
			throw string("nombre de ligne ou de colonne incompatible");
		}
		else 
		{
			Matrice<T> newMat(nombreLigne,M.nombreColonne);
			T compt=0;
			int i,j,k;
			

			for (i=0; i<nombreLigne; i++)
			{
				for (j=0; j<nombreLigne; j++)
				{
					compt = 0;
					for (k=0; k<nombreColonne; k++)
					{
						compt+=t[i][k]*M.get(k,j);
					}
					newMat.set(i,j,compt);
				}
			}
			return newMat;
		}
	}
	catch(string const& chaine)
   	{
    	cerr << chaine << endl;
  	}
	
}

template<typename T> 
bool Matrice<T>::operator==(Matrice<T> M) // comparaison de deux matrices
{
	/*if (!(nombreColonne == M.nombreColonne) || !(nombreLigne == M.nombreLigne))
	{
		cout << "matrices differentes";
	}
	else 
	{
		Matrice<T> newMat();
		int i,j,k;
		
		for (i=0; i<nombreLigne; i++)
		{
			for (j=0; j<nombreColonne; j++)
			{
				if(t[i][j] != M.get(i,j))
				{
					cout << "\nMatrices differentes";
					return false;
				}
			}
		}
	}	*/
	return true;
}



/*template<typename T> 
::ostream& operator<<(::ostream& ofs, Matrice<T>& M){ // operateur <<
	ofs << "(";
	int i = 0;
	int  j = 0; 

	for (i; i<M.getNombreLigne(); i++) // on parcourt toutes les lignes
	{ 
		ofs << " ";
		for (j; j<M.getNombreColonne(); j++)
		{ 										//on parcourt toutes les colonnes
			ofs << M(i,j) << " " ;
		}
		if(i<M.getNombreLigne()-1)
		ofs <<  :: endl << " ";
	}
	ofs << ")" <<  :: endl;
	return ofs;
}*/

template <typename T> // Destructeur
Matrice<T>::~Matrice()
{
	int i =0;
	for (i; i < nombreLigne; i++)
		delete[] t[i];
	delete[] t;
}

template<typename T>
void Matrice<T>::afficher()
{
	cout << "Matrice :" << endl;
	int i;
	int j;

	for(i=0; i<nombreLigne; i++)
	{
		for(j=0; j<nombreColonne; j++) 
		{
			cout << t[i][j] << " ";
		}
		cout << " " << endl; //saut de ligne pour chaque ligne
	}	
	cout << "" << endl; 
}

#endif