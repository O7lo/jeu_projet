#include "Joueur.h"

void Joueur::regarder(){
	std::cout << "\n\n-----------"<<salleActuelle_->getNom()<< "-----------";
	std::cout << std::endl << salleActuelle_->getDescription();
	Salle** voisins = salleActuelle_->getVoisins();
	for (int i = 0; i < 4; i++) {
		if (voisins[i] != nullptr) {
			std::cout << "\nIl y a " << voisins[i]->getNom() << " " << nomsDirections[i] << " (" << symbolesDirections[i]<<")";
		}
	}
}

void Joueur::deplacer(int direction) {
	if (salleActuelle_->getVoisins()[direction] == nullptr) {
		std::cout << "\nJe ne peux pas aller " << nomsDirections[direction]<<", il n'y a rien par là.";
	}
	else {
		std::cout << "\nJe me déplace " << nomsDirections[direction]<<".";
		salleActuelle_ = salleActuelle_->getVoisins()[direction];
		regarder();
	}
}