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
	void setSalleDeDepart(Salle* salle) { salleDeDepart_ = salle; }
	Salle* getSalleDeDepart() { return salleDeDepart_; }
private:
	std::vector<std::unique_ptr<Salle>> salles_;
	Salle* salleDeDepart_;
};