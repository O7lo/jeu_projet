#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <map>
#include "Objet.h"
#include "ObjetSerrure.h"
#include "ObjetDeplacable.h"



class ObjetNormal :public Objet {
public:
	ObjetNormal(std::string nom, std::string description, std::vector<std::string> motsImportants, std::string utilisation): Objet(nom, description, motsImportants), utilisation_(utilisation){}

	ObjetNormal(const ObjetNormal& autre) {
		nom_ = autre.nom_;
		description_ = autre.description_;
	}

	Objet* ajouterObjet(ObjetNormal& objet) {
		objets_.insert({ objet.getNom(), std::make_unique<ObjetNormal>(objet) });
		std::cout << "\nobjet ajoutée: " << objets_[objet.getNom()]->getNom() << "\t";
		return objets_[objet.getNom()].get();
	}

	Objet* ajouterObjet(ObjetSerrure& objet) {
		objets_.insert({ objet.getNom(), std::make_unique<ObjetSerrure>(objet) });
		std::cout << "\nobjet ajoutée: " << objets_[objet.getNom()]->getNom() << "\t";
		return objets_[objet.getNom()].get();
	}

	Objet* ajouterObjet(ObjetDeplacable& objet) {
		objets_.insert({ objet.getNom(), std::make_unique<ObjetDeplacable>(objet) });
		std::cout << "objet ajoutée: " << objets_[objet.getNom()]->getNom() << "\t";
		return objets_[objet.getNom()].get();
	}

	void utiliser() override {
		std::cout << utilisation_;
	}

private:
	std::string utilisation_;
	std::map < std::string, std::unique_ptr<Objet>> objets_;

};