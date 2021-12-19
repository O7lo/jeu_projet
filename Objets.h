#include <string>
#include <iostream>

class Objets {
public:
	Objets(std::string nom, std::string description) :nom_(nom), description_(description) {}
	std::string getNom() { return nom_; }
	void setNom(std::string nom) { nom_ = nom; }
	std::string getDescription() { return description_; }
	void setDescription(std::string description) { description_ = description; }

private:
	std::string nom_;
	std::string description_;
};