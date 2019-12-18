#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>
using namespace std ;
#include "Forme.hpp"


//Déclaration de la classe Rectangle, qui hérite de la classe Forme
class Rectangle : public Forme {
	//Données et méthode privées
	private :
		uint largeur ; //Type entier non-signé permettant de représenter la largeur
		uint hauteur ; //Type entier non-signé permettant de représenter la hauteur
		void ecrire(ostream & os) const override ; //permet d'écrire le nom de la forme ainsi que ses attributs. 
		
	//Méthodes publiques	
	public :
		Rectangle(ulong couleur, uint x, uint y, uint largeur, uint hauteur) ; //Constructeur de Rectangle
		Rectangle(istream & is) ; //Constructeur à partir d'n flux passé en paramètre
		~Rectangle() override ; //Destructeur virtuel
		void dessiner(EZWindow & fenetre, bool isActive = false) const override ; //Permet de dessiner un rectangle dans la fenêtre
		inline double perimetre() const override { return ((largeur*2)+(hauteur*2)) ; } //Retourne le périmètre du rectangle
		inline uint getLargeur() const { return largeur ; } //getter retournant la largeur
		inline void setLargeur(uint _largeur) { largeur = _largeur ; } //setter donnant l'accès à la largeur
		inline uint getHauteur() const { return hauteur ; } //getter retournant la hauteur
		inline void setHauteur(uint _hauteur) { hauteur = _hauteur ; } //setter donnant l'accès à la hauteur
};
#endif
