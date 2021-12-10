#pragma once
#include <memory>
#include <vector>
#include <iostream>

class Plateau {
public:
	Plateau() = default;
	void ajouterSalle(std::unique_ptr<Salle> salle);
private:
	std::vector<std::unique_ptr<Salle>> salles_;
};