#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>


class Objet {
public:
	
	Objet(std::string nom, std::vector<std::string> motsImportants, std::string description,std::string utilisation) : nom_(nom), motsImportants_(motsImportants), description_(description),utilisation_(utilisation) { std::cout << "\n\n"<<motsImportants_[0]; }
	Objet() = default;
	virtual ~Objet()=default;
	std::string getNom() { return nom_; }
	std::string getDescription() { return description_; }
	std::vector<std::string> getMotsImportants() { return motsImportants_; }
	void setNom(std::string nom) { nom_ = nom; }
	void setDescription(std::string description) { description_ = description; }
	void setMotsImportant(std::vector<std::string> motsImportants) { motsImportants_ = motsImportants; }
	virtual std::unique_ptr<Objet> clone() = 0;

	virtual void utiliser() = 0;
	
protected:
	std::string nom_;
	std::vector<std::string> motsImportants_;
	std::string description_;
	std::string utilisation_;
	
};