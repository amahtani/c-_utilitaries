#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <math.h>

using namespace std;


class Vecteur
{

private:

	float x;
	float y;


public:
	
	Vecteur(float a, float b)
	{
		x = a;
		y = b;
	}

	const float Getx();
	const float Gety();

	void Setx(float x);
	void Sety(float y);
	void SetVecteur(float x, float y);

	void affiche();
	float norme();
	Vecteur* addition(const Vecteur);
	
};

/*const int Getx()
 	{return _x;} 

const int Gety()
 	{return _y;} 
*/
 
void Vecteur::Setx(float x)
	{x = x;}

void Vecteur::Sety(float y)
	{y = y;}

/*void Vecteur::SetVecteur(float x, float y)
	{x = x; y = y;}
*/
int main()
{
	Vecteur* vec1 = new Vecteur(2,3);
	Vecteur* vec2 = new Vecteur(3,4);

	vec1->affiche();
	vec2->affiche();
	
	vec2->norme();
	Vecteur* vec3 = vec2->addition(*vec1);

	vec3->affiche();
	
	delete(vec1);
	delete(vec2);
	delete(vec3);

	return 1;
}