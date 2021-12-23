#include "Plateau.h"

Salle* Plateau::ajouterSalle(Salle& salle) {
	salles_.insert({ salle.getNom(),std::make_unique<Salle>(salle) });
	std::cout << "salle ajoutée: " << salles_[salle.getNom()]->getNom() << "\t";
	return salles_[salle.getNom()].get();
}

void Plateau::ajouterSalle(Salle& salle, Direction direction, std::string voisin) {
	ajouterSalle(salle);
	connecterVoisins(salle.getNom(), direction, voisin);
}

void Plateau::ajouterSalle(std::string nom, std::string description) {
	salles_.insert({ nom,make_unique<Salle>(nom,description) });
}

void Plateau::connecterVoisins(std::string salle1, Direction direction, std::string salle2) {
	salles_[salle1]->connecterVoisin(salles_[salle2].get(),direction);
	salles_[salle2]->connecterVoisin(salles_[salle1].get(), directionsInverses[static_cast<int>(direction)]);
}