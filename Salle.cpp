#include "Salle.h"

void Salle::connecterVoisin(Salle* voisin, Direction direction){
	int dir=static_cast<int>(direction);
	voisins_[dir] = voisin;
	std::cout << "voisin connect�: " << voisins_[dir]->getNom()<<" "<< nomsDirections[dir] <<"\t";
}