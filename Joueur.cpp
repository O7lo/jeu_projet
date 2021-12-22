#include "Joueur.h"

void Joueur::executerCommande(std::string commande) {
	std::string argument = commande.substr(commande.find(" ")+1,commande.size());
	std::string action = commande.substr(0, commande.find(" "));
	try {
		auto fonction = commandes_.at(action);
		(this->*fonction)(argument);
	}
	catch (const std::out_of_range&) {
		std::cout << "Commande inconnue. Utiliser (C) pour afficher la liste des commandes.";
	}
	
}

void Joueur::regarder(std::string quoi){
	if (quoi == "regarder" || quoi == "r") {
		std::cout << "\n\n-----------"<<salleActuelle_->getNom()<< "-----------";
		std::cout << std::endl << salleActuelle_->getDescription();
		int i = 0;
		for (auto voisin:salleActuelle_->getVoisins()) {
			if (voisin != nullptr) {
				std::cout << "\nIl y a " << voisin->getNom() << " " << nomsDirections[i] << " (" << symbolesDirections[i]<<")";
			}
			i++;
		}
		if (salleActuelle_->aUnObjet()) {
			std::cout << "\n\nJe vois :";
					for (auto nomObjet : salleActuelle_->getNomsObjets()) {
						std::cout << "\n\t" << nomObjet;
					}
		}
	}
	else {
		std::map<std::string, Objet*> motsImportants = salleActuelle_->getMotsImportantsObjets();
		bool objetTrouve = false;
		for (auto [mot,objetPtr] : motsImportants) {
			if (quoi.find(mot) != quoi.npos) {
				std::cout<<"\n"<<objetPtr->getDescription();
				objetTrouve = true;
				break;
			}
		}
		if (!objetTrouve) {
			std::cout << "\nDésolé, je ne trouve pas cet objet.";
		}
	}
}

void Joueur::utiliser(std::string) {
	
}

void Joueur::deplacer(Direction direction) {
	int dir=static_cast<int>(direction);
	if (salleActuelle_->getVoisins()[dir] == nullptr) {
		std::cout << "\nJe ne peux pas aller " << nomsDirections[dir]<<", il n'y a rien par là.";
	}
	else {
		std::cout << "\nJe me déplace " << nomsDirections[dir]<<".";
		salleActuelle_ = salleActuelle_->getVoisins()[dir];
		regarder();
	}
}

void Joueur::afficherInventaire(std::string) {

}

void Joueur::afficherCommandes(std::string) {
	std::cout << "afficherCommandes"; 
}

void Joueur::quitter(std::string) {
	//si on a l'enfant dans notre inventaire: message jeu gagné, sinon message jeu échoué
	std::cout << "quitter"; 
	continuerAJouer_ = false;
}

void Joueur::jouer() {
	continuerAJouer_ = true;
	regarder();
	std::string commande;
	while (continuerAJouer_) {
		std::cout << "\n>";
		std::getline(std::cin, commande);
		std::transform(commande.begin(), commande.end(), commande.begin(),
			[](unsigned char c) { return std::tolower(c); }); //ne fonctionne pas pour tous les caractères de tous les encodages mais fonctionne pour tous ceux que nous utilisons. 
		executerCommande(commande);
	}
}