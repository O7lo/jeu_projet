#include "Plateau.h"

void Plateau::ajouterSalle(std::unique_ptr<Salle> salle) {
	salles_.push_back(move(salle));
	std::cout << "salle ajout�e: " << *salles_.back();
}