#pragma once
//#include "Salle.h"
//#include "Plateau.h"
//#include "Objet.h"

class Joueur {
public:
	Joueur(Salle* salle) { salleActuelle_ = salle; }

	void setSalleActuelle(Salle* salle) { salleActuelle_ = salle; }
	Salle* getSalleActuelle() { return salleActuelle_; }
	void regarder();
	//void regarder(const Objet& objet);
	//void utiliser(Objet& objet);
	void deplacer(int direction);
private:
	Salle* salleActuelle_;
};