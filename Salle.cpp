#include "Salle.h"

void Salle::connecterVoisin(Salle* voisin, int direction){
	voisins_[direction] = voisin;
	std::string nomDirection=nomsDirections[direction];
	std::cout << "voisin connect�: " << voisins_[direction]->getNom()<<" au "<<nomDirection;
}