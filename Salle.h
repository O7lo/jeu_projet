#pragma once
#include <iostream>
#include "constantesGlobales.h"
//#include "Plateau.h"

class Salle {
public:
	Salle(std::string nom, std::string description) { nom_ = nom; description_ = description; }
	void setNom(std::string nom) { nom_ = nom; }
	std::string getNom() { return nom_; }
	void setDescription(std::string description) { description_ = description; }
	std::string getDescription() { return description_; }
	void connecterVoisin(Salle* voisin,int direction);
	Salle** getVoisins() { return voisins_; }

private:
	std::string nom_="pas de nom";
	std::string description_="pas de description";
	Salle* voisins_[4] = { nullptr,nullptr,nullptr,nullptr };
};