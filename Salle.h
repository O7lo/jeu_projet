#pragma once
#include <memory>
#include <vector>
#include <iostream>

inline extern const std::string nomsDirections[4] = { "nord","sud","est","ouest" };

class Salle {
public:
	Salle(std::string nom, std::string description) { nom_ = nom; description_ = description; }
	void setNom(std::string nom) { nom_ = nom; }
	std::string getNom() { return nom_; }
	void setDescription(std::string description) { description_ = description; }
	std::string getDescription() { return description_; }
	void connecterVoisin(Salle* voisin,int direction);
	Salle** getVoisins() { return voisins_; }

private:
	std::string nom_;
	std::string description_;
	Salle* voisins_[4] = { nullptr,nullptr,nullptr,nullptr };
};