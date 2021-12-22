#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <map>
#include "Objet.h"
#include "ObjetSerrure.h"


class ObjetNormal :public Objet {
public:
	ObjetNormal(std::string nom, std::string description) :nom_(nom), description_(description) {};
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
	}


	void utiliser() override {
		std::cout << "Bonjour";
	}

private:
	std::string nom_;
	std::string description_;
	std::string motsImportants_;
	std::map < std::string, std::unique_ptr<ObjetSerrure>> objetsNormaux_;

};