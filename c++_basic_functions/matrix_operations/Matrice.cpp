
#include "Matrice.hpp"
#include "Vecteur.hpp"




int main(int argc, char **argv)
{
	cout << "Matrice de int\n";
	Matrice<int> mat(2,2);
	mat.set(0,1,5);
	mat.set(1,0,2);
	mat.set(1,1,2);
	mat.set(0,0,1);
	mat.afficher();

	cout << "Matrice de double\n";
	Matrice<float> matt(2,2);
	matt.set(0,1,5.0);
	matt.set(1,0,1.0);
	matt.set(1,1,0);
	matt.set(0,0,1.0);
	matt.afficher();

	cout << "Matrice de float\n";
	Matrice<double> mattt(2,2);
	mattt.set(1,0,0);
	mattt.set(0,0,1.43);
	mattt.set(1,1,0.4343);
	mattt.set(0,1,1.3454);
	mattt.afficher();


	mattt(2,2) = 42;		// SEGFAULT ICI !!!!
	//-------------------------------
	cout << "mattt\n";
	mattt.afficher();				//  Test de l'operateur () en lecture
	//-------------------------------
	Matrice<double> matttt(mattt);			//  Test du constructeur par copie 
	matttt.afficher();
	//-------------------------------
	Matrice<double>  mattttt = matttt;			//  Test de l'operateur =
	mattttt.afficher();
	//-------------------------------
	Matrice<double>  mattttttt(mattttt + matttt);		//  Test de l'operateur +
	mattttttt.afficher();

	Matrice<int>  matttttttt(mat);
	matttttttt = mat + mat;
	matttttttt.afficher();
	//-------------------------------
	Matrice<int>  mattttttttt = mat - mat;		//  Test de l'operateur -
	mattttttttt.afficher();
	//-------------------------------
	Matrice<int> matttttttttt(2,2);			//  Test de l'operateur *
	matttttttttt.set(1,0,0);
	matttttttttt.set(2,0,1);
	matttttttttt.set(3,1,0);
	matttttttttt.set(4,1,1);

	matttttttttt = matttttttttt * matttttttttt ;
	matttttttttt.afficher();
	//-------------------------------
	Matrice<int> mattttttttttt = mat + 1;			// Test de l'addition avec un scalaire
	mattttttttttt.afficher();
	//-------------------------------
	Matrice<int> matttttttttttt = mattttttttttt - 1;		// Test de la soustraction avec un scalaire
	matttttttttttt.afficher();
	//-------------------------------
	Matrice<int> mattttttttttttt = mat * 2;		// Test de la multiplication avec un scalaire
	mattttttttttttt.afficher();
	//-------------------------------
	if(mat == matttttttt) cout << "les matrices mat et matt sont egales" << "\n" << endl;		//  Test de l'operateur ==
	//-------------------------------
	//cout << "\nmat =\n"<< mat << endl;		// Test de l'opérateur <<
	//-------------------------------
	Vecteur<int> vect(3);			// Test de la creation d'un vecteur
	vect.afficher();				//et affichage
	//-------------------------------
	Vecteur<int> vectt(3);					// Test du produit scalaire
	Vecteur<int> vecttt(3);
	vectt.set(1,0,0);
	vectt.set(2,1,0);
	vectt.set(3,2,0);
	vecttt.set(1,0,0);
	vecttt.set(2,1,0);
	vecttt.set(3,2,0);
	vectt.afficher();
	vecttt.afficher();

	//cout << "\n produit scalaire =  \n" << vectt.produitScalaire(vecttt) << endl;
	//-------------------------------
	//cout << "\n produit vectoriel =  \n" << vectt.produitVectoriel(vecttt) << endl;		 // Test du produit vectoriel
	//-------------------------------
	//cout << "\n norme du vecteur =  \n" << vectt.norme() << endl;		// Test du calcul de la norme
	//-------------------------------
	//cout << "\n vect(1,1) = \n" << vectt(0,0) << endl;			// Test de l'operateur []
	//-------------------------------
	//vectt[0] = 42;
	//cout << "\n vect(1,1) = " << vectt(0,0) << endl;		//  Test de l'operateur en ecriture
	
	return 0;
}
