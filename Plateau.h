#pragma once
#include <memory>
#include <map>
#include <iostream>
#include "Salle.h"
#include "constantesGlobales.h"

class Plateau {
public:
	Plateau() = default;
	void ajouterSalle(Salle& salle);
	void ajouterSalle(Salle& salle, Direction direction, std::string voisin);
	void ajouterSalle(std::string nom, std::string description);
	void connecterVoisins(std::string salle1, Direction direction, std::string salle2);
	void ajouterSalleDeDepart(Salle& salle) { ajouterSalle(salle); salleDeDepart_ = salles_[salle.getNom()].get(); }
	void ajouterSalleDeDepart(std::string nom, std::string description) 
		{ ajouterSalle(nom, description); salleDeDepart_ = salles_[nom].get(); }
	void setSalleDeDepart(std::string nom) { salleDeDepart_ = salles_[nom].get(); }
	Salle* getSalleDeDepart() const { return salleDeDepart_; }
private:
	std::map<std::string,std::unique_ptr<Salle>> salles_;
	Salle* salleDeDepart_=nullptr;
};