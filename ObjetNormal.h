#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <map>
#include "Objet.h"
#include "ObjetSerrure.h"


class ObjetNormal :public Objet {
public:
	ObjetNormal(std::string nom, std::string description, std::vector<std::string> motsImportants, std::string utilisation):
		Objet(nom, description, motsImportants), utilisation_(utilisation){}

	ObjetNormal(const ObjetNormal& autre) {
		nom_ = autre.nom_;
		description_ = autre.description_;
	}

	void ajouterObjet(ObjetSerrure& objet)  {
		objetsNormaux_.insert({ objet.getNom(), std::make_unique<ObjetSerrure>(objet) });
		std::cout << " objet ajoutee:  " << objetsNormaux_[objet.getNom()]->getNom();
	}


	void utiliser() override {
		std::cout << utilisation_;
	}

private:
	std::string utilisation_;
	std::map < std::string, std::unique_ptr<ObjetSerrure>> objetsNormaux_;

};