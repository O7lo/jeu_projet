#pragma once
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "Objet.h"
#include "Joueur.h"

class ObjetSerrure : public Objet {
public:
	ObjetSerrure(std::string nom, std::string description, std::vector<std::string> motsImportants, Salle* connection) : Objet(nom, description, motsImportants), connection_(connection) {}

	ObjetSerrure(const ObjetSerrure& autre) {
		nom_ = autre.nom_;
		description_ = autre.description_;
	}

	void utiliser() override {
		salleActuel_->connecterVoisin(connection_, Direction::est);
		
	}

private:
	Joueur joueur_;
	Salle* salleActuel_ = joueur_.getSalleActuelle();
	Salle* connection_;
};