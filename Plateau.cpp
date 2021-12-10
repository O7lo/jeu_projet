#include "Plateau.h"

void Plateau::ajouterSalle(std::unique_ptr<Salle> salle) {
	salles_.push_back(move(salle));
	std::cout << "salle ajoutée: " << salles_.back()->getNom();
}

void Plateau::connecterVoisins(Salle* salle1, int direction,Salle* salle2) {
	salle1->connecterVoisin(salle2,direction);
	salle2->connecterVoisin(salle1, directionsInverses[direction]);
}