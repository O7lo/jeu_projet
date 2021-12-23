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
#include "ObjetNormal.h"
#include "ObjetSerrure.h"
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



	Salle cuisine("la cuisine","C'est sale, il y a plein de bouffe partout, une tonne de mouches à fruits et une odeur d'oeufs pourris.");
	Salle entree("l'entree", "Cette salle est l'entree, tapis rouge sur le sol");
	Salle corridor("le corridor","Les murs sont tachés de sang, le vieux plancher de bois craque à chacun de mes pas, il fait sombre, les ampoules sont brûlées.");
	Salle salon("le salon", "Ce n'est pas le genre de salon auquel je suis habitué. Pauvres enfants, vivre dans cette laideur c'est horrible! Il n'y a même pas de sapin, où vais-je déposer les cadeaux?");
	Salle labo("le laboratoire clandestin", "Il y a une forte odeur de produits chimiques ici, je n'aime pas ça. On dirait que c'est une sorte de laboratoire clandestin, il y a des toiles de plastiques un peu partout, des ustensiles de verre, des brûleurs et des bacs blanc sur lesquels il y a des étiquettes décrivant les produits dangereux qu'ils contiennent.");
	Salle passageSecret("le passage secret", "Il fait un noir total ici, je ne vois strictement rien. J'aurais besoin de quelque chose pour m'éclairer.");
	Salle salleDeBain("la salle de bain", "C'est immonde! Mais quelle horreur! Je sens que je vais vômir si je reste ici trop longtemps! Il y a des selles partout sur les murs, le plancher et même le plafond! Le seul endroit qui a été épargné par le cataclysme fécal qui s'est produit ici c'est le bol de toilette, quelle ironie!");
	Salle chambre("la chambre", "Merde, il y a quelqu'un dans le lit!\t*éteint rapidement la lumière*\nJ'espère qu'il ne m'a pas vu!\t*écoute en silence*\t...\n*rallume la lumière*\tEst-ce qu'il est mort?");

	ObjetNormal junkie("un homme cadavérique, surement un junkie", "Il ressemble vraiment à un cadavre, mais je vois son torse se soulever légèrement quand il inspire. Il a vraiment mauvaise mine, je peux voir la forme de ses os sous sa peau mince de couleur maladive. Il s'est endormi avec une bière qu'il tient encore fermement dans sa main gauche comme un enfant qui se serait endormi avec son toutou préféré. Tiens, on dirait une clef qui dépasse de sous son aisselle.",/*"Je ne peux pas croire que je suis en train de faire ca, je voulais juste donner des cadeaux aux enfants moi!Mais cette clef peut probablement m'aider à sortir de cette maison de cauchemards. Ca pue la mort! Ce junkie ne s'est probablement pas lavé depuis des mois!Je me sens si sale maintenant que je l'ai touché! Pauvre type. J'espère qu'il ne sera pas faché que j'aie pris sa clef.",*/ { "homme","cadavérique","junkie" });
	/*ObjetDeplacable clef("une vieille clef en acier rouillée", "C'est une clef que j'ai trouvée sous l'aisselle du junkie. Elle est rouillée et elle empeste la sueur.", {"clef","acier","rouillée"});*/
	/*ObjetDeplacable enfant("un enfant en piteux état, c'est un jeune garçon.", "Il a l'air terrorisé! et il est dans un état pitoyable. Son visage me rappelle celui du Junkie, ce doit être son père. L'enfant tient un toutou à l'air maléfique. Il a un air si défraichi que j'ai peur que même la laveuse ne saurait le débarrasser de la crasse dont il est recouvert. Peu importe. Je suis venu ici avec une seule mission : donner un cadeau à un enfant. J'ai justement une chose à lui offrir : de la liberté! Il faut que je trouve un moyen de le sortir de là.", { "enfant","jeune","garçon","garcon" });*/
	ObjetNormal poison("une substance douteuse, je crois que c'est du poison à rat", "Du poison à rat se trouve par-terre dans le laboratoire. Des rats morts jonchent le sol. On dirait un poison fait maison. OH! Il se passe ma foi des choses malsaines dans ce lieu. ", { "substance","poison" });
	/*unique_ptr<Objet> serrure = make_unique<Objet> (string("un trou d'une forme qui fait penser à une serrure"), string("mais pourquoi il y aurait une serrure au fond d'un bol de toilette? C'est vraiment un endroit bizzare ici."), { "trou","serrure" });*/
	ObjetSerrure serrure("un trou d'une forme qui fait penser à une serrure", "mais pourquoi il y aurait une serrure au fond d'un bol de toilette? C'est vraiment un endroit bizzare ici.", { "trou","serrure" });
	ObjetNormal bolDeToilette("le bol de toilette tout blanc", "Ca \"clash\" vraiment avec le rete de la pièce, c'est la seule chose qui est propre, je me demande pourquoi.", { "bol","toilette","blanc" });


	

	Salle* chambre_=plateau.ajouterSalle(chambre);
	Salle* salleDeBain_=plateau.ajouterSalle(salleDeBain);
	Salle* passageSecret_=plateau.ajouterSalle(passageSecret);
	Salle* labo_=plateau.ajouterSalle(labo);
	Salle* salon_=plateau.ajouterSalle(salon);
	Salle* cuisine_=plateau.ajouterSalle(cuisine);
	Salle* entree_=plateau.ajouterSalle(entree);
	Salle* corridor_=plateau.ajouterSalle(corridor);
	
	chambre_->ajouterObjet(junkie);
	//junkie.ajouterObjet(clef);
	//chambre.ajouterObjet(enfant);
	labo_->ajouterObjet(poison);

	plateau.connecterVoisins("la chambre", Direction::ouest, "le corridor");
	plateau.connecterVoisins("la salle de bain", Direction::sud, "la chambre");
	plateau.connecterVoisins("la salle de bain", Direction::ouest, "la cuisine");
	plateau.connecterVoisins("le laboratoire clandestin", Direction::est, "le passage secret");
	plateau.connecterVoisins("le salon", Direction::est, "le corridor");
	plateau.connecterVoisins("le corridor", Direction::nord, "la cuisine");
	plateau.connecterVoisins("l'entree", Direction::nord, "le corridor");

	plateau.setSalleDeDepart("le salon");


	return plateau;
}

void introduireJeu() {
	cout << "\n\n~~~~~~~~~~~~~~~~ Le père noël est arrivé deux mois trop tôt! ~~~~~~~~~~~~~~~~";
	cout << "\n\n------------------------ Un jeu de Pascal et Arthur ------------------------\n";
}

int main(int argc, char* argv[])
{
	initialiserBibliothequeCours(argc, argv);
	
	Plateau plateau = creerPlateau();

	introduireJeu();
	Joueur joueur(plateau);
	joueur.jouer();
}