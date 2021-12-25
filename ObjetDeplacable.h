#pragma once
#include <iostream>
#include <string>
#include <memory>

#include "Objet.h"

class ObjetDeplacable :public Objet {
public:
	ObjetDeplacable(std::string nom, std::vector<std::string> motsImportants, std::string description, std::string utilisation) : Objet(nom, motsImportants, description,utilisation) {}

	ObjetDeplacable(const ObjetDeplacable& autre) :
		Objet(autre.nom_, autre.motsImportants_, autre.description_, autre.utilisation_) {}

	std::unique_ptr<Objet> clone() {
		return std::make_unique<ObjetDeplacable>(*this);
	}

	void utiliser() override {
		std::cout << utilisation_;
	}

private:



};