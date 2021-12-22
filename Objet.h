#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>


class Objet {
public:
	Objet() = default;
	~Objet() = default;
	std::string getNom() { return nom_; }
	std::string getDescription() { return description_; }
	std::vector<std::string> getMotsImportant() { return motsImportant_; }
	void setNom(std::string nom) { nom_ = nom; }
	void setDescription(std::string description) { description_ = description; }
	void setMotsImportant(std::vector<std::string> motsImportant) { motsImportant_ = motsImportant; }

	virtual void utiliser() = 0;
	
private:
	std::string nom_;
	std::string description_;
	std::vector<std::string> motsImportant_;
};