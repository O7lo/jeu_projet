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
	plateau.ajouterSalle(salon);
	plateau.ajouterSalle(cuisine);
	plateau.ajouterSalle(entree);
	plateau.ajouterSalle(corridor);
	plateau.connecterVoisins("Salon", 2, "Corridor");
	plateau.connecterVoisins("Corridor", 0, "Cuisine");
	plateau.connecterVoisins("Entree", 0, "Corridor");
	plateau.setSalleDeDepart("Salon");
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
	char commande=' ';
	while (commande != 'Q') {
		cout << "\n>";
		cin >> commande;
		commande = toupper(commande); //on a un avertissement de perte possible de données car toupper fait une conversion de int en char mais vu que le int en question vient d'un char il n'y a pas de problème. 
		switch (commande) {
		case 'R':
			joueur.regarder();
			break;
		case 'N':
			joueur.deplacer(0);
			break;
		case 'S':
			joueur.deplacer(1);
			break;
		case 'E':
			joueur.deplacer(2);
			break;
		case 'O':
			joueur.deplacer(3);
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
	
	/*
		//? Tout a été mis dans le main, aucun orienté-objet.
		cout << "Ceci est mon super jeu mal programmé.\n\n";

	//? Tout peux modifier ces variables (aucune encapsulation).
	int salle = 0;  //? Quelle valeur est quelle salle?
	string commande;
	bool look = true;  //? La logique pour fonctionnalité look n'est pas bien séparée/regroupée (voir les plusieurs modifications et utilisations de look partout dans le code).

	while (true) {
		switch (salle) {  //? Un gros switch/case, imaginez s'il y avait des centaines de salles...
		case 0:
			if (look) //? Aucune séparation de la logique par rapport au contenu du jeu.
				cout << "Vous êtes dans l'entrée. Il y a un tapis sur le sol.\n"
				"Couloir est au nord (N)\n"  //? Les textes des directions sont "hard-codées", on peut se tromper et il faut modifier plusieurs endroits pour ajouter un lien.
				"Salon est à l'est (E)\n";  //? Aussi comment on fait pour pouvoir ajouter des liens pendant le jeu (demandé au livrable 2)?
			look = false;
			cout << "> ";
			cin >> commande;
			if (commande.size() == 1) {
				switch (commande[0]) {
				case 'N': salle = 2; look = true; break;  //? On remet look = true dans chaque direction, c'est clairement de la duplication de code; la logique qui fait l'affichage lorsqu'on entre dans une salle devrait être à un seul endroit dans le code.
				case 'E': salle = 1; look = true; break;
				default: cout << "Ne peut pas aller là\n";
				}
			}
			else if (commande == "look") look = true;
			else cout << "Je ne sais pas ça\n";
			break;

			//? Clairement de la duplication de code dans chaque 'case'.
		case 1:
			if (look)
				cout << "Vous êtes dans le salon.\n"
				"Entrée est à l'ouest (W)\n";
			look = false;
			cout << "> ";
			cin >> commande;
			if (commande.size() == 1) {
				switch (commande[0]) {
				case 'W': salle = 0; look = true; break;
				default: cout << "Ne peut pas aller là\n";
				}
			}
			else if (commande == "look") look = true;  //? Imaginez si on voulair ajouter d'autres commandes...
			else cout << "Je ne sais pas ça\n";
			break;

		case 2:
			if (look)
				cout << "Vous êtes dans le couloir.\n"
				"Cuisine est au nord (N)\n"
				"Petite chambre est à l'ouest (W)\n"
				"Entrée est au sud (S)\n";
			look = false;
			cout << "> ";
			cin >> commande;
			if (commande.size() == 1) {
				switch (commande[0]) {
				case 'N': salle = 4; look = true; break;
				case 'W': salle = 3; look = true; break;
				case 'S': salle = 0; look = true; break;
				default: cout << "Ne peut pas aller là\n";
				}
			}
			else if (commande == "look") look = true;
			else cout << "Je ne sais pas ça\n";
			break;

		case 3:
			if (look)
				cout << "Vous êtes dans une petite chambre. Elle n'a rien de spécial autre que d'être petite.\n"
				"Couloir est à l'est (E)\n";
			look = false;
			cout << "> ";
			cin >> commande;
			if (commande.size() == 1) {
				switch (commande[0]) {
				case 'E': salle = 2; look = true; break;
				default: cout << "Ne peut pas aller là\n";
				}
			}
			else if (commande == "look") look = true;
			else cout << "Je ne sais pas ça\n";
			break;

		case 4:
			if (look)
				cout << "Vous êtes dans la cuisine. Elle est très jaune 'beurre' comme la mode d'une certaine époque.\n"
				"Couloir est au sud (S)\n";
			look = false;
			cout << "> ";
			cin >> commande;
			if (commande.size() == 1) {
				switch (commande[0]) {
				case 'S': salle = 2; look = true; break;
				default: cout << "Ne peut pas aller là\n";
				}
			}
			else if (commande == "look") look = true;
			else cout << "Je ne sais pas ça\n";
			break;
		}
	}
}
*/