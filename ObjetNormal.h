#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <map>
#include "Objet.h"
#include "ObjetSerrure.h"


class ObjetNormal :public Objet {
public:
	ObjetNormal(std::string nom, std::string description, std::vector<std::string> motsImportants): Objet(nom, description, motsImportants){}

	ObjetNormal(const ObjetNormal& autre) {
		nom_ = autre.nom_;
		description_ = autre.description_;
		for (const auto& [nom, objet] : autre.objetsNormaux_) {
			std::string nomCopie = nom;
			objetsNormaux_.insert({ nomCopie, std::make_unique<ObjetSerrure>(*objet) });
		}
	}

	void ajouterObjet(ObjetSerrure& objet)  {
		objetsNormaux_.insert({ objet.getNom(), std::make_unique<ObjetSerrure>(objet) });
		std::cout << " objet ajoutee:  " << objetsNormaux_[objet.getNom()]->getNom();
	}


	void utiliser() override {
		std::cout << ""
	}

private:

	std::map < std::string, std::unique_ptr<ObjetSerrure>> objetsNormaux_;

};