#pragma region "Bibliothèques"//{

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <gsl/span>
#include <cppitertools/range.hpp>
#include <cppitertools/enumerate.hpp>

#include <memory>
#include <map>
#include "Objet.h"
#include "Plateau.h"
#include "Salle.h"
#include "Joueur.h"


//#if __has_include("gtest/gtest.h")
//#include "gtest/gtest.h"
//#endif

#if __has_include("bibliotheque_cours.hpp")
#include "bibliotheque_cours.hpp"
#define BIBLIOTHEQUE_COURS_INCLUS
using bibliotheque_cours::cdbg;
#else
auto& cdbg = clog;
#endif

#if __has_include("verification_allocation.hpp")
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#endif

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
#ifdef BIBLIOTHEQUE_COURS_INCLUS
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par défaut.

	// cdbg.setTee(&clog);  // Décommenter cette ligne pour que cdbg affiche sur la console en plus de la "Sortie" du débogueur.

	// bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un résultat de test.
#endif
}

using namespace std;
using namespace std::literals;
using namespace iter;
using namespace gsl;

#pragma endregion//}

Plateau creerPlateau() {
	Plateau plateau;

	Salle cuisine("Cuisine","C'est sale, il y a plein de bouffe partout, une tonne de mouches à fruits et une odeur d'oeufs pourris.");
	Salle entree("Entree", "Cette salle est l'entree, tapis rouge sur le sol");
	Salle corridor("Corridor","Les murs sont tachés de sang, le vieux plancher de bois craque à chacun de mes pas, il fait sombre, les ampoules sont brûlées.");
	Salle salon("Salon", "Ce n'est pas le genre de salon auquel je suis habitué. Pauvres enfants, vivre dans cette laideur c'est horrible! Il n'y a même pas de sapin, où vais-je déposer les cadeaux?");
	Salle labo("Labo", "Il y a une forte odeur de produits chimiques ici, je n'aime pas ça. On dirait que c'est une sorte de laboratoire clandestin, il y a des toiles de plastiques un peu partout, des ustensiles de verre, des brûleurs et des bacs blanc sur lesquels il y a des étiquettes décrivant les produits dangereux qu'ils contiennent.");
	Salle passageSecret("Passage secret", "Il fait un noir total ici, je ne vois strictement rien. J'aurais besoin de quelque chose pour m'éclairer.");
	Salle salleDeBain("Salle de bain", "C'est immonde! Mais quelle horreur! Je sens que je vais vômir si je reste ici trop longtemps! Il y a des selles partout sur les murs, le plancher et même le plafond! Le seul endroit qui a été épargné par le cataclysme fécal qui s'est produit ici c'est le bol de toilette, quelle ironie!");
	Salle chambre("Chambre", "Merde, il y a quelqu'un dans le lit!\t*éteint rapidement la lumière*\nJ'espère qu'il ne m'a pas vu!\t*écoute en silence*\t...\n*rallume la lumière*\tEst-ce qu'il est mort?");

	plateau.ajouterSalle(chambre);
	plateau.ajouterSalle(salleDeBain);
	plateau.ajouterSalle(passageSecret);
	plateau.ajouterSalle(labo);
	plateau.ajouterSalle(salon);
	plateau.ajouterSalle(cuisine);
	plateau.ajouterSalle(entree);
	plateau.ajouterSalle(corridor);

	plateau.connecterVoisins("Chambre", Direction::ouest, "Corridor");
	plateau.connecterVoisins("Salle de bain", Direction::sud, "Chambre");
	plateau.connecterVoisins("Salle de bain", Direction::ouest, "Cuisine");
	plateau.connecterVoisins("Labo", Direction::est, "Passage secret");
	plateau.connecterVoisins("Salon", Direction::est, "Corridor");
	plateau.connecterVoisins("Corridor", Direction::nord, "Cuisine");
	plateau.connecterVoisins("Entree", Direction::nord, "Corridor");

	plateau.setSalleDeDepart("Salon");
	Objet clef("Cle", "C'est la clee pour la porte");
	Objet toilet("toilet", "plein de merde");

	unique_ptr<Objet> cle = make_unique<Objet>(clef);
	
	salleDeBain.ajouterObjet(toilet);
	


	return plateau;
}

void afficherCommandes() {
	cout << "\nRegarder (R)\naller au nord (N)\naller au sud (S)\naller à l'est (E)\naller à l'ouest (O)\nquitter le jeu (Q)";
}

void introduireJeu() {
	cout << "\n\n~~~~~~~~~~~~~~~~ Le père noël est arrivé deux mois trop tôt! ~~~~~~~~~~~~~~~~";
	cout << "\n\n------------------------ Un jeu de Pascal et Arthur ------------------------";
	cout << "\nListe des commandes:";
	afficherCommandes();
}

int main(int argc, char* argv[])
{
	initialiserBibliothequeCours(argc, argv);

	Plateau plateau = creerPlateau();
	introduireJeu();
	Joueur joueur(plateau);
	joueur.regarder();
	string commande = " ";
	while (commande[0] != 'Q') {
		cout << "\n>";
		cin >> commande;
		commande[0] = toupper(commande[0]); //on a un avertissement de perte possible de données car toupper fait une conversion de int en char mais vu que le int en question vient d'un char il n'y a pas de problème. 
		switch (commande[0]) {
		case 'R':
			joueur.regarder();
			break;
		case 'N':
			joueur.deplacer(Direction::nord);
			break;
		case 'S':
			joueur.deplacer(Direction::sud);
			break;
		case 'E':
			joueur.deplacer(Direction::est);
			break;
		case 'O':
			joueur.deplacer(Direction::ouest);
			break;
		case 'C':
			afficherCommandes();
			break;
		case 'Q':
			break;
		default:
			cout << "Commande inconnue. Utiliser (C) pour afficher la liste des commandes.";
		}
	}
}