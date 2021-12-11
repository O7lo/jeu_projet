#include "Salle.h"

void Salle::connecterVoisin(Salle* voisin, int direction){
	voisins_[direction] = voisin;
	std::cout << "voisin connecté: " << voisins_[direction]->getNom()<<" "<< nomsDirections[direction] <<"\t";
}