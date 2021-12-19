#include "Joueur.h"

void Joueur::regarder(){
	std::cout << "\n\n-----------"<<salleActuelle_->getNom()<< "-----------";
	std::cout << std::endl << salleActuelle_->getDescription();
	int i = 0;
	for (auto voisin:salleActuelle_->getVoisins()) {
		if (voisin != nullptr) {
			std::cout << "\nIl y a " << voisin->getNom() << " " << nomsDirections[i] << " (" << symbolesDirections[i]<<")";
		}
		i++;
	}
}

void Joueur::deplacer(Direction direction) {
	int dir=static_cast<int>(direction);
	if (salleActuelle_->getVoisins()[dir] == nullptr) {
		std::cout << "\nJe ne peux pas aller " << nomsDirections[dir]<<", il n'y a rien par là.";
	}
	else {
		std::cout << "\nJe me déplace " << nomsDirections[dir]<<".";
		salleActuelle_ = salleActuelle_->getVoisins()[dir];
		regarder();
	}
}