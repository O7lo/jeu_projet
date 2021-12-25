#pragma once
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "Objet.h"
//#include "Joueur.h"

class ObjetSerrure : public Objet {
public:
	ObjetSerrure(std::string nom, std::vector<std::string> motsImportants, std::string description,std::string utilisation) : Objet(nom, motsImportants, description,utilisation) {}

	ObjetSerrure(const ObjetSerrure& autre) :
		Objet(autre.nom_, autre.motsImportants_, autre.description_, autre.utilisation_) {}

	std::unique_ptr<Objet> clone() {
		return std::make_unique<ObjetSerrure>(*this);
	}

	void utiliser() override {
		std::cout << utilisation_;
		/*salleActuel_->connecterVoisin(connection_, Direction::est);*/
		
	}

private:

	//Joueur joueur_;
	//Salle* salleActuel_ = joueur_.getSalleActuelle();
	//Salle* connection_;
};