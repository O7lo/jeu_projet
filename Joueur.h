#pragma once
#include "Salle.h"
#include <iostream>	
#include "constantesGlobales.h"
#include "Plateau.h"
//#include "Objet.h"

class Joueur {
public:
	Joueur(const Plateau& plateau) { salleActuelle_ = plateau.getSalleDeDepart(); }

	void setSalleActuelle(Salle& salle) { salleActuelle_ = &salle; }
	Salle* getSalleActuelle() { return salleActuelle_; }
	void regarder();
	//void regarder(const Objet& objet);
	//void utiliser(Objet& objet);
	void deplacer(Direction direction);
private:
	Salle* salleActuelle_;
};