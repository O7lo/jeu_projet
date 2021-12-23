#include "Salle.h"

std::vector<std::string> Salle::getNomsObjets() const{
	std::vector<std::string> nomsObjets;
	for (auto&& clef : objets_ | std::ranges::views::keys) {
		nomsObjets.push_back(clef);
	}
	return nomsObjets;
}

std::map<std::string, Objet*> Salle::getMotsImportantsObjets() const {
	std::map<std::string, Objet*> motsImportantsObjets;
	for (auto&& clef : objets_ | std::ranges::views::keys) {
		for (auto mot : objets_.at(clef)->getMotsImportants()) {
			motsImportantsObjets[mot]=objets_.at(clef).get();
		}
	}
	return motsImportantsObjets;
}

void Salle::connecterVoisin(Salle* voisin, Direction direction){
	int dir=static_cast<int>(direction);
	voisins_[dir] = voisin;
	std::cout << "voisin connecté: " << voisins_[dir]->getNom()<<" "<< nomsDirections[dir] <<"\t";
}

void Salle::ajouterObjet(ObjetNormal& objet) {
	objets_.insert({ objet.getNom(), std::make_unique<ObjetNormal>(objet)});
	std::cout << "\nobjet ajoutée: " << objets_[objet.getNom()]->getNom() << "\t";
}

void Salle::ajouterObjet(ObjetSerrure& objet) {
	objets_.insert({ objet.getNom(), std::make_unique<ObjetSerrure>(objet) });
	std::cout << "\nobjet ajoutée: " << objets_[objet.getNom()]->getNom() << "\t";
}

//void Salle::ajouterObjet(ObjetDeplacable& objet) {
//	objets_.insert({ objet.getNom(), std::make_unique<ObjetDeplacable>(objet) });
//	std::cout << "objet ajoutée: " << objets_[objet.getNom()]->getNom() << "\t";
//}