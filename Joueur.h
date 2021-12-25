#pragma once
#include "Salle.h"
#include <iostream>	
#include "constantesGlobales.h"
#include "Plateau.h"
#include <algorithm>


class Joueur {
public:
	Joueur(const Plateau& plateau) { salleActuelle_ = plateau.getSalleDeDepart(); }
	void setSalleActuelle(Salle& salle) { salleActuelle_ = &salle; }
	Salle* getSalleActuelle() { return salleActuelle_; }
	void regarder(std::string quoi="regarder");
	void utiliser(std::string);
	void deplacerNord(std::string) { deplacer(Direction::nord); }
	void deplacerSud(std::string) { deplacer(Direction::sud); }
	void deplacerEst(std::string) { deplacer(Direction::est); }
	void deplacerOuest(std::string) { deplacer(Direction::ouest); }
	void deplacer(Direction direction);
	void quitter(std::string);
	void afficherCommandes(std::string = "");
	void executerCommande(std::string commande);
	void afficherInventaire(std::string);
	void jouer();
	std::vector<std::string> getNomsObjets() const;
private:
	Salle* salleActuelle_;
	std::map<std::string, void (Joueur::*)(std::string) > commandes_ = { 
		{std::string("regarder"),&Joueur::regarder },
		{std::string("r"),&Joueur::regarder },
		{std::string("utiliser"),&Joueur::utiliser},
		{std::string("u"),&Joueur::utiliser},
		{std::string("inventaire"),&Joueur::afficherInventaire},
		{std::string("i"),&Joueur::afficherInventaire},
		{std::string("nord"),&Joueur::deplacerNord},
		{std::string("sud"),&Joueur::deplacerSud} ,
		{std::string("est"),&Joueur::deplacerEst} ,
		{std::string("ouest"),&Joueur::deplacerOuest} ,
		{std::string("n"),&Joueur::deplacerNord} ,
		{std::string("s"),&Joueur::deplacerSud} ,
		{std::string("e"),&Joueur::deplacerEst} ,
		{std::string("o"),&Joueur::deplacerOuest} ,
		{std::string("quitter"),&Joueur::quitter} ,
		{std::string("q"),&Joueur::quitter} ,
		{std::string("c"),&Joueur::afficherCommandes} ,
		{std::string("commandes"),&Joueur::afficherCommandes} };
	std::map<std::string, std::unique_ptr<ObjetNormal>> inventaire_;
	bool continuerAJouer_ = false;
	Objet* trouverObjet(std::string);
};