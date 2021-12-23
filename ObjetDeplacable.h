#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "Joueur.h"
#include "Objet.h"

class ObjetDeplacable :public Objet {
public:
	ObjetDeplacable(std::string nom, std::string description, std::vector<std::string> motsImportants) : Objet(nom, description, motsImportants){}

	void utiliser() override {
		

	}
private:


};