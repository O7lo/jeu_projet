#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <map>
#include "Objet.h"
#include "ObjetSerrure.h"
#include "ObjetDeplacable.h"
#include <algorithm>



class ObjetNormal :public Objet {
public:
	ObjetNormal(std::string nom, std::vector<std::string> motsImportants, std::string description, std::string utilisation): Objet(nom, motsImportants, description,utilisation){}

	ObjetNormal(const ObjetNormal& autre) : 
		Objet(autre.nom_,autre.motsImportants_,autre.description_, autre.utilisation_){
		std::for_each(autre.objets_.begin(), autre.objets_.end(), [&]
		(const std::pair<const std::string, std::unique_ptr<Objet>>& paire)
			{ objets_[paire.first] = paire.second->clone(); });
	}

	std::unique_ptr<Objet> clone() {
		return std::make_unique<ObjetNormal>(*this);
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
	std::map < std::string, std::unique_ptr<Objet>> objets_;

};