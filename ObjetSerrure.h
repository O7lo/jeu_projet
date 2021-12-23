#pragma once
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "Objet.h"

class ObjetSerrure : public Objet {
public:
	ObjetSerrure(std::string nom, std::string description, std::vector<std::string> motsImportants) :nom_(nom), description_(description), motsImportants_(motsImportants) {}

	std::string getNom() { return nom_; }
	std::string getDescription() { return description_; }
	std::vector<std::string> getMotsImportant() { return motsImportants_; }
	void setNom(std::string nom) { nom_ = nom; }
	void setDescription(std::string description) { description_ = description; }
	void setMotsImportant(std::vector<std::string> motsImportant) { motsImportants_ = motsImportant; }

	void utiliser() override {
		std::cout << "bon";
	}

private:
	std::string nom_;
	std::string description_;
	std::vector<std::string> motsImportants_;
};