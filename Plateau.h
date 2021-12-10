#pragma once
#include <memory>
#include <vector>
#include <iostream>
//#include "Salle.h"

inline extern const std::string nomsDirections[4] = { "au nord","au sud","à l'est","à l'ouest" };
inline extern const std::string symbolesDirections[4] = { "N","S","E","O" };
inline extern const int directionsInverses[4] = { 1,0,3,2 };

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