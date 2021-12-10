#pragma once
#include <memory>
#include <vector>
#include <iostream>
#include "Salle.h"

class Plateau {
public:
	Plateau() = default;
	void ajouterSalle(std::unique_ptr<Salle> salle);
	void connecterVoisins(Salle* salle1, int direction, Salle* salle2);
private:
	std::vector<std::unique_ptr<Salle>> salles_;
};