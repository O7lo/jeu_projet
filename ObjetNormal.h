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

	std::string getNom() { return nom_; }
	std::string getDescription() { return description_; }
	std::vector<std::string> getMotsImportant() { return motsImportants_; }
	void setNom(std::string nom) { nom_ = nom; }
	void setDescription(std::string description) { description_ = description; }
	void setMotsImportant(std::vector<std::string> motsImportant) { motsImportants_ = motsImportant; }

	void ajouterObjet(ObjetSerrure& objet)  {
		objetsNormaux_.insert({ objet.getNom(), std::make_unique<ObjetSerrure>(objet) });
		std::cout << " objet ajoutee:  " << objetsNormaux_[objet.getNom()]->getNom();
	}


	void utiliser() override {
		std::cout << "Bonjour";
	}

private:
	std::string nom_;
	std::string description_;
	std::vector<std::string> motsImportants_;
	std::map < std::string, std::unique_ptr<ObjetSerrure>> objetsNormaux_;

};