#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>


class Objet {
public:
	
	Objet(std::string nom, std::string description, std::vector<std::string> motsImportants): nom_(nom), description_(description), motsImportants_(motsImportants) {}
	Objet() = default;
	~Objet() = default;
	std::string getNom() { return nom_; }
	std::string getDescription() { return description_; }
	std::vector<std::string> getMotsImportant() { return motsImportants_; }
	void setNom(std::string nom) { nom_ = nom; }
	void setDescription(std::string description) { description_ = description; }
	void setMotsImportant(std::vector<std::string> motsImportants) { motsImportants_ = motsImportants; }

	virtual void utiliser() = 0;
	
protected:
	std::string nom_;
	std::string description_;
	std::vector<std::string> motsImportants_;
};