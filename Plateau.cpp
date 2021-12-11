#include "Plateau.h"

void Plateau::ajouterSalle(Salle& salle) {
	salles_.insert({ salle.getNom(),std::make_unique<Salle>(salle) });
	std::cout << "salle ajoutée: " << salles_[salle.getNom()]->getNom() << "\t";
}

void Plateau::ajouterSalle(std::string nom, std::string description) {
	salles_.insert({ nom,make_unique<Salle>(nom,description) });
}

void Plateau::connecterVoisins(std::string salle1, int direction, std::string salle2) {
	salles_[salle1]->connecterVoisin(salles_[salle2].get(),direction);
	salles_[salle2]->connecterVoisin(salles_[salle1].get(), directionsInverses[direction]);
}
