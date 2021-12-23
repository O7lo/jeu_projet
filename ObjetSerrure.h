#pragma once
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "Objet.h"

class ObjetSerrure : public Objet {
public:
	ObjetSerrure(std::string nom, std::string description, std::vector<std::string> motsImportants) : Objet(nom, description, motsImportants) {}

	ObjetSerrure(const ObjetSerrure& autre) {
		nom_ = autre.nom_;
		description_ = autre.description_;
	}

	void utiliser() override {
		std::cout << "bon";
	}

private:
	
};