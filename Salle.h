#pragma once
#include <iostream>
#include <memory>
#include <string>
#include "constantesGlobales.h"
#include "Objet.h"
#include <vector>
#include <map>
#include <ranges>

class Salle {
public:
	Salle(std::string nom, std::string description) { nom_ = nom; description_ = description; }
	Salle(const Salle& autre) { 
		nom_ = autre.nom_; 
		description_ = autre.description_; 
		for (const auto& [nom,objet] : autre.objets_) {
			std::string nomCopie = nom;
			objets_.insert({ nomCopie,std::make_unique<Objet>(*objet) });
		}
	}
	void setNom(std::string nom) { nom_ = nom; }
	std::string getNom() { return nom_; }
	void setDescription(std::string description) { description_ = description; }
	std::string getDescription() { return description_; }
	void connecterVoisin(Salle* voisin,Direction direction);
	std::array<Salle*,4> getVoisins() { return voisins_; }
	Objet* getObjet(std::string nom)const { return objets_.at(nom).get(); }
	std::vector<std::string> getNomsObjets() const;
	std::map<std::string, Objet*> getMotsImportantsObjets() const;
	bool aUnObjet() { return objets_.size() > 0; }
	void ajouterObjet(Objet& objet);


private:
	std::string nom_="pas de nom";
	std::string description_="pas de description";
	std::array<Salle*, 4> voisins_ = { nullptr,nullptr,nullptr,nullptr };
	std::map<std::string, std::unique_ptr<Objet>> objets_;
};