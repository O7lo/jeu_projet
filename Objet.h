#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <map>

class Objet {
public:
	Objet(std::string nom, std::string description) :nom_(nom), description_(description) {};
	std::string getNom() const { return nom_; }
	void setNom(std::string nom) { nom_ = nom; }
	std::string getDescription() const { return description_; }
	void setDescription(std::string description) { description_ = description; }
	/*void ajouterObjet(Objet& objet) {
		objets_.insert({ objet.getNom(), std::make_unique<Objet>(objet) });
	}*/

private:
	
	std::string nom_;
	std::string description_;
	//std::map<std::string, std::unique_ptr<Objet>> objets_;
};