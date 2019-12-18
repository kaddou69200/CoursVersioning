#ifndef FORMES_HPP
#define FORMES_HPP

#include <iostream>
using namespace std ;
#include "ez-draw++.hpp"
#include "Forme.hpp"
#include "Rectangle.hpp"
#include "Cercle.hpp"
#include "Ellipse.hpp"
#include "Carre.hpp"
#include "Triangle.hpp"
#include "Image.hpp"
#include "Polygone.hpp"


//Déclaration de la classe FormeS
class FormeS {
	//Données privées
	private :
		size_t maxformes ; //indique le nombre maximum de formes
		size_t nbformes ; //indique le nombre de forme
		Forme ** formes ; //tableau qui stocke des pointeurs sur une Forme
		
	public :
		FormeS(size_t taille = 200) ; //Constructeur de FormeS
		~FormeS() ; //Destructeur
		void ajouter(Forme * forme) ; //Permet d'ajouter une forme dans le tableau 
						  //(plus exactement un pointeur sur une forme)
		void dessiner(EZWindow & f) const ; //Permet de dessiner les formes présentent dans le tableau
		Forme * isOver(uint x, uint y) ; //Permet de sélectionner une forme
		friend ostream & operator<<(ostream & os, FormeS formes) ; //Opérateur d'injection
		void charger(istream & is) ; //Permet de charger plusieurs formes
		void sauver(ostream &) ; //Permet d'écrire dans un flux les formes du tableau
		
} ;

#endif 
