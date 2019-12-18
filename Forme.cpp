#include <iostream>
using namespace std ;
#include "Forme.hpp"
#include "Rectangle.hpp"
#include "Carre.hpp"
#include "Ellipse.hpp"
#include "Cercle.hpp"
#include "Triangle.hpp"
#include "Image.hpp"
#include "Polygone.hpp"

//Implantation de la classe Forme 

//Constructeur
//Prend en paramètre trois entiers pour la couleur et les coordonnées de l'ancre
Forme::Forme(ulong _couleur, uint _x, uint _y)
	//liste d'initialisation
	: couleur(_couleur), ancre(_x, _y), selected(false), epais(1) , remplissage(false) 
	{ cerr << "Constructeur FORME" ; }

//Constructeur par copie
//Prend en paramètre une référence constante
Forme::Forme(const Forme & orig)
	: couleur(orig.couleur), ancre(orig.ancre), selected(false), epais(orig.epais), remplissage(orig.remplissage)
	{ cerr << "Constructeur de copie FORME" ; }

//Constructeur
//Prend en paramètre un flux	
Forme::Forme(istream & is)
	: couleur(0), ancre(0, 0), epais(1), remplissage(false)
	{ is >> couleur >> ancre >> epais >> remplissage ; cout << "construction forme copie ";}
	
//Destructeur
Forme::~Forme()
{ cerr << "Destructeur de FORME" ; }

//Permet de connaitre la sélection d'ancre
bool Forme::isOver(uint x, uint y)
{ return ancre.isOver(x, y) ; }

//Fonction virtuelle permettant de dessiner une forme 
void Forme::dessiner(EZWindow & w, bool active) const
{ 
	
	w.setColor(ez_black) ; //la couleur initial est le noir
	ancre.dessiner(w, active) ;
	w.setColor(couleur) ;  //on règle la couleur
	w.setThick(epais) ; //on règle l'épaisseur'
	
}


//Cette fonction va écrire dans le flux passé en paramètre les attributs d'une forme
void Forme::ecrire(ostream & os) const
{ os <<" "<< couleur << " " << ancre.getX() << " " << ancre.getY() << " " << epais << " " << remplissage << " "/*<< " " << epais << " " << remplissage*/; }

//Opérateur d'injection
//Prend en paramètre un flux et une référence constante sur une Forme
ostream & operator<<(ostream & os, const Forme & forme)
{ forme.ecrire(os) ; return os ; }

//Prend en paramètre un flux
Forme * Forme::charger(istream & is) 
{ 
	string type_forme ;
	is >> type_forme ; //On extrait du flux passé en paramètres
			     //le nom d'une forme.
			     //Selon le cas, une nouvelle instance d'une certaine forme est créée.
			     
	
	if (type_forme == "Rectangle")
		{
			return new Rectangle(is) ;
		}
	else if (type_forme == "Carre")
		{
			return new Carre(is) ;
		}
	else if (type_forme == "Ellipse")
		{
			return new Ellipse(is) ;
		}
	else if (type_forme == "Cercle")
		{
			return new Cercle(is) ;
		}
	else if (type_forme == "Triangle")
		{
			return new Triangle(is) ;
		}
	else if (type_forme == "Image")
		{
			return new Image(is) ;
		}
	else if (type_forme == "Polygone")
		{
			return new Polygone(is) ;
		}
	
	else 
		{
			throw runtime_error ("Pas de formes correspondantes") ;
		}
		
	}
