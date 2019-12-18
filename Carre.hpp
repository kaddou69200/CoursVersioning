#ifndef CARRE_HPP
#define CARRE_HPP

#include <iostream>
using namespace std ;
#include "ez-draw++.hpp"
#include "Forme.hpp"




//déclaration de la classe Carre, qui hérite de la classe Forme
class Carre : public Forme {
	//Donnée et méthode privée
	private :
		uint cote ; 						//contient la longueur d'un côté
		void ecrire(ostream & os) const override ; 	//permet d'écrire le nom de la forme ainsi que ses attributs. 
	
	//Fonction publique	
	public :
		Carre(ulong couleur, uint x, uint y, uint cote ) ; //Constructeur de Carre
		Carre(istream & is) ; 				  //Constructeur de Carre à partir d'un flux passé en paramètre
		~Carre() override ; 					  //Destructeur virtuel 
		void dessiner(EZWindow & fenetre, bool isActive = false) const ; //Permet de dessiner un carre dans la fenêtre
		inline double perimetre() const override { return (cote*4) ; } //Fonction qui retourne le périmètre
		inline uint getCote() const { return cote ; } //Fonction getter qui permet d'avoir la longueur d'un côté
		inline void setCote( uint _cote) { cote = _cote ; } //Fonction setter qui permet de paramétrer la longueur d'un côté
};

#endif
