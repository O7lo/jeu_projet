#include "Salle.h"

void Salle::connecterVoisin(Salle* voisin, int direction){
	voisins_[direction] = voisin;
	std::cout << "voisin connecté: " << voisins_[direction]->getNom()<<" "<< nomsDirections[direction] <<"\t";
}

void Salle::ajouterObjet(Objets& objet) {
	objets_.insert({ objet.getNom(), std::make_unique<Objets>(objet) });
	std::cout << "objet ajoutee dans la salle: " << objets_[objet.getNom()]->getNom() << "\t";
}