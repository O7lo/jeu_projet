#pragma once
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "Objet.h"

class ObjetSerrure : public Objet {
public:
	ObjetSerrure(std::string nom, std::string description) :nom_(nom), description_(description) {}


	void utiliser() override {
		std::cout << "bon";
	}
private:
	std::string nom_;
	std::string description_;
	std::string motsImportant_;
};