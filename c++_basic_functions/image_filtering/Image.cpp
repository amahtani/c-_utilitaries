/******************************** TP numéro 1 de c++ : Ankur MAHTANI & Bastien PESAMOSCA - Exercice 2 ********************************/


#include <iostream>
#include "Image.hpp"
#include <fstream>
#include <stdexcept>
#include <string>
#include <cassert>
#include <stdlib.h>
#include "Filtre.hpp"
#include "FiltreAddition.hpp"
#include "FiltreMoyenne.hpp"
#include "SuiteDeFiltre.hpp"

int main()
{
	
	//Question 2
	Image i1("cairo.pgm");
	i1.write("cairo_copie.pgm");

	Image i2(i1);
	i2.write("cairo_copie2.pgm"); 		// pour le filtre addition

	Image i3(i1);
	i3.write("cairo_copie3.pgm"); 		//pour le filtre moyenneur

	Image i4(i1);
	i4.write("cairo_copie4.pgm"); 		// pour la suite de filtres


	//Question 4
	FiltreAddition f1(100);
	f1.apply(i2);
	i2.write("cairo_add.pgm");


	//Question 5
	FiltreMoyenne f2(5);
	f2.apply(i3);
	i3.write("cairo_moy.pgm");


	//Question 6
	SuiteDeFiltre s;
	s.add(&f1); 								//filtre addtion
	s.add(&f2); 								// filtre moyennneur
	s.apply(i4);
	i4.write("cairo_suite.pgm");

	return 0;
}

//constructeur
Image::Image(const char* nom)
{
	load(nom);
}

//constructeur par copie
Image::Image(Image& i)
{
	w = i.w;
	h = i.h;
	//copier en parcourant le tableau 
	data = (unsigned char *)malloc(w*h*sizeof(unsigned char));
	for(int j=0; j<w*h; j++)
	{
		data[j] = i.data[j];
	}
}


// destructeur
Image::~Image()
{
	delete[] data;
}

//methodes
void Image::load(const char* nom)
{
	std::ifstream ifs(nom);
	assert(ifs.good());
	std::string format;
	std::string t;
	ifs >> format;
	ifs >> w >> h;
	//ifs >> taille;
	data = (unsigned char *)malloc(w*h*sizeof(unsigned char));
	ifs.read((char *) data,w*h);
}


void Image::write(const char* nom)
{
	std::ofstream ofs(nom);
	assert(ofs.good());
	ofs << "P5\n" << w << " " << h << "\n" << "255\n" << std::endl;
	ofs.write((char*) data, w*h);
	ofs.close();
}

//accesseurs
unsigned char Image::get(int i, int j)
{
	return data[i*w + j];
}

void Image::set(int i, int j, unsigned char valeur)
{
	data[i*w + j] = valeur;
}

int Image::get_w()
{
	return w;
}

int Image::get_h()
{
	return h;
}