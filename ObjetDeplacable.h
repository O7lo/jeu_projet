#pragma once
#include <iostream>
#include <string>
#include <memory>

#include "Objet.h"

class ObjetDeplacable :public Objet {
public:
	ObjetDeplacable(std::string nom, std::string description, std::vector<std::string> motsImportants, std::string utilisation) : Objet(nom, description, motsImportants), utilisation_(utilisation) {}

private:
	std::string utilisation_;


};