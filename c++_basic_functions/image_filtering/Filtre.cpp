/******************************** TP numéro 1 de c++ : Ankur MAHTANI & Bastien PESAMOSCA - Exercice 2 ********************************/

// Declaration de la methode de la classe Filtre
#include <iostream>
#include "Image.hpp"
#include "Filtre.hpp"
#include <fstream>
#include <stdexcept>
#include <string>
#include <cassert>
#include <stdlib.h>

const std::string& Filtre::get_name() const
{
	
	return nom;
	
}