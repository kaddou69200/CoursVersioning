#ifndef FORME_HPP
#define FORME_HPP
#include <iostream>
using namespace std ;
#include "Point.hpp"

//déclaration de la classe Forme
//Cette classe est abstraite
class Forme {
	//Données protégées
	protected : 
		ulong couleur ; //Type entier non-signé permettant de représenter une couleur
		Point ancre ; //Type Point permettant de représenter l'ancre d'une forme
		bool selected ; //Type booléen permettant de savoir si une ancre est sélectionnée
		int epais; //Type entier permettant de représenter l'épaisseur d'un trait'
		bool remplissage; //Type booléen permettant de savoir si la forme est remplie
	
	//Méthodes publiques	
	public :
		Forme(ulong _couleur, uint _x, uint _y); //Constructeur
		Forme(const Forme & origine) ; //Constructeur par copie
		Forme(istream & is) ; //Constructeur à partir d'un flux
		virtual ~Forme() ; //Destructeur virtuel
		inline ulong getCouleur() const { return couleur ; } //getter retournant la couleur
		inline void setCouleur(ulong _couleur) { couleur = _couleur ; } //setter donnant accès à la couleur
		inline Point getAncre() const { return ancre ; } //getter retournant l'ancre
		virtual inline void setAncre(uint _x, uint _y) { ancre.setXY(_x, _y) ; } //setter donnant accès à l'ancre
		virtual bool isOver(uint x, uint y) ; //Cette fonction permet de savoir si l'ancre est sélectionnée
		inline void setEpais(int _epais){epais = _epais;} //setter donnant accès à l'épaisseur'
		inline int getEpais () const {return epais;} //getter retournant lépaisseur
		virtual void setTransp(){} //set la transparence pour une image 
		inline void setRemplissage (bool _remplissage){remplissage = _remplissage;} // set le remplissage d'une forme
		inline bool getRemplissage () const {return remplissage;} //get le remplissage d'une forme
		virtual void dessiner(EZWindow &, bool active = false) const ; //Fonction virtuelle permettant de dessiner une forme 
		virtual double perimetre() const = 0 ; //Fonction virtuelle pure permettant de retourner le périmètre
		
		virtual void ecrire(ostream & os)  const ; //Fonction virtuelle qui va permettre d'écrire le nom d'une forme et ses attributs dans un flux passé en paramètre
		static Forme * charger(istream & is) ; //Cette fonction créer une instance
		friend ostream & operator<<(ostream & os, const Forme & f) ; //Fonction amie
										     //Operateur d'injection
};

#endif
