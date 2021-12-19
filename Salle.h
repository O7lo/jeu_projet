#pragma once
#include <iostream>
#include "constantesGlobales.h"
#include <array>

class Salle {
public:
	Salle(std::string nom, std::string description) { nom_ = nom; description_ = description; }
	void setNom(std::string nom) { nom_ = nom; }
	std::string getNom() { return nom_; }
	void setDescription(std::string description) { description_ = description; }
	std::string getDescription() { return description_; }
	void connecterVoisin(Salle* voisin,Direction direction);
	std::array<Salle*,4> getVoisins() { return voisins_; }

private:
	std::string nom_="pas de nom";
	std::string description_="pas de description";
	std::array<Salle*, 4> voisins_ = { nullptr,nullptr,nullptr,nullptr };
};