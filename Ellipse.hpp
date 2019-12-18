#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include <iostream>
#include <cmath>
using namespace std ;
#include "Forme.hpp"

//Déclaration de la classe Ellipse, qui hérite de la classe Forme
class Ellipse : public Forme {
	//données et méthodes privées
	private :
		uint demiLargeur ; //Type entier non-signé permettant de représenter la demi-largeur.
		uint demiHauteur ; //Type entier non-signé permettant de représenter la demi-hauteur.
		void ecrire(ostream & os) const override ; //permet d'écrire le nom de la forme ainsi que ses attributs. 
	
	//Méthodes publiques	
	public :
		Ellipse(ulong couleur, uint x, uint y, uint demiLargeur, uint demiHauteur) ; //Constructeur d'Ellipse
		Ellipse(istream & is) ; //Constructeur à partir d'un flux passé en paramètre
		~Ellipse() override ; //Destructeur virtuel
		void dessiner(EZWindow & fenetre, bool isActive = false) const ; //Permet de dessiner une ellipse dans la fenêtre
		inline double perimetre() const override { return (2*3.14159*sqrt(0.5*(demiLargeur*demiLargeur+demiHauteur*demiHauteur))) ; } //Cette fonction retourne le périmètre d'une ellipse
		inline uint getDemiLargeur() const { return demiLargeur ; } //getter retournant la demi-largeur
		inline void setDemiLargeur(uint _demiLargeur) { demiLargeur = _demiLargeur ; } //setter donnant accès à la demi-largeur
		inline uint getDemiHauteur() const { return demiHauteur ; } //getter retournant la demi-hauteur
		inline void setDemiHauteur(uint _demiHauteur) { demiHauteur = _demiHauteur ; } //setter donnant accès à la demi-hauteur
};

#endif
