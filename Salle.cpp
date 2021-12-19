#include "Salle.h"

void Salle::connecterVoisin(Salle* voisin, Direction direction){
	int dir=static_cast<int>(direction);
	voisins_[dir] = voisin;
	std::cout << "voisin connecté: " << voisins_[dir]->getNom()<<" "<< nomsDirections[dir] <<"\t";
}

void Salle::ajouterObjet(Objets& objet) {
	objets_.insert({ objet.getNom(), std::make_unique<Objets>(objet) });
	std::cout << "objet ajoutee dans la salle: " << objets_[objet.getNom()]->getNom() << "\t";
}