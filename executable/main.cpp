#include <iostream>
#include <string>

using namespace std;

int main(){

	//cout << "Hell World !";
	//cin.ignore();
	/*string mot1 = "test de mots ";
	string mot2 = "débiles";
	string mots = mot1 + mot2;
	cout << mots;
	*/

	/*string prenom;
	cout << "\n Prénom :\n";
	cin >> prenom;
	cin.ignore();
	cout << "\n votre prénom est : \n" << prenom; 
	*/

	//addition de 2 nombres
	/*int a,b, res;
	cout << "\n Entrez deux nombres a et b : \n";	
	//cout << "\n a = \n";
	cin >> a;
	cin.ignore();
	cin >> b;
	cin.ignore();
	res = a + b;
	cout << "\n" << a << " + " << b << " = " << res << "\n";
	*/

	//les conditions
	int age;
	int gender(0);		
	cout << "\n\nEntrez votre âge et votre sexe :\n\n";
	cin >> age;


	if(age >= 18){
		cout << "\nVous êtes majeur !\n\n";
	}
	else if(age < 18){
		cout << "\nVous êtes mineurs :(\n\n";
	}
	


	//showMOTD();
	

	cin.ignore();
	return 0;
}
