#pragma once
#include <string>
#include <iostream>
#include <memory>

class Objet {
public:
	Objet(std::string nom, std::string description) :nom_(nom), description_(description) {};
	std::string getNom() const { return nom_; }
	void setNom(std::string nom) { nom_ = nom; }
	std::string getDescription() const { return description_; }
	void setDescription(std::string description) { description_ = description; }

private:
	std::string nom_;
	std::string description_;
};