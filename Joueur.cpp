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
		Objet* objet = trouverObjet(quoi);
		if(objet!=nullptr){
			std::cout<<"\n"<<objet->getDescription();
		}
		else { std::cout << "\nDésolé, je ne trouve pas cet objet."; }
	}
}

void Joueur::utiliser(std::string quoi) {
	Objet* objet = trouverObjet(quoi);
	if (objet != nullptr) {
		objet->utiliser();
	}
	else { std::cout << "\nDésolé, je ne trouve pas cet objet."; }
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
	if (getNomsObjets().size() > 0) {
		std::cout << "\nHOHOHO! J'ai avec moi :";
		for (auto nomObjet : getNomsObjets()) {
			std::cout << "\n\t" << nomObjet;
		}
	}
	else std::cout << "\nHOHOHO! Je n'ai rien pris avec moi encore.";
}

void Joueur::afficherCommandes(std::string) {
	std::cout << "\nListe des commandes:";
	std::cout << "\n\tRegarder (r) + nom d'un objet (optionnel)\n\tutiliser (u) + nom d'un objet\n\taller au nord (n)\n\taller au sud (s)\n\taller à l'est (e)\n\taller à l'ouest (o)\n\tquitter le jeu (q)";
}

void Joueur::quitter(std::string) {
	//si on a l'enfant dans notre inventaire: message jeu gagné, sinon message jeu échoué
	std::cout << "\n---------------------------------------------------------\n\nOh! HOHO! Mais quel étourdis je fais! Je suis magique!\nJe peux donc sortir d'ici quand je veux grâce à la magie de noël!     **POUF!**";
	if (inventaire_.find("enfant") != inventaire_.end()) {
		std::cout << "\n Allez, viens par ici petit, je t'emmene avec moi au pôle-nord. C'est bien plus chaleureux qu'ici tu verras!\n\n~~~~~~~~~~FÉLICITATIONS! VOUS AVEZ GAGNÉ!~~~~~~~~~~\n\n\n\n";
	}
	else std::cout << "\n\n~~~~~~~~~~VOUS AVEZ PERDU, ESSAYEZ ENCORE!~~~~~~~~~~\n\n\n\n";
	continuerAJouer_ = false;
}

void Joueur::jouer() {
	continuerAJouer_ = true;
	afficherCommandes();
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

Objet* Joueur::trouverObjet(std::string quoi) {
	for (auto [mot, objetPtr] : salleActuelle_->getMotsImportantsObjets()) {
		if (quoi.find(mot) != quoi.npos) {
			return objetPtr;
		}
	}
	return nullptr;
}

std::vector<std::string> Joueur::getNomsObjets() const {
	std::vector<std::string> nomsObjets;
	for (auto&& clef : inventaire_ | std::ranges::views::keys) {
		nomsObjets.push_back(clef);
	}
	return nomsObjets;
}