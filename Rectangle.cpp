#include <iostream>
using namespace std ;
#include "Rectangle.hpp"

//Implantation de la classe Rectangle

//Constructeur
//qui prend en paramètre cinq entier
//pour la couleur, l'ancre, la largeur et la hauteur
Rectangle::Rectangle(ulong _couleur, uint _x, uint _y, uint _largeur, uint _hauteur)
	: Forme(_couleur, _x, _y), largeur(_largeur), hauteur(_hauteur) //Liste d'initialisation avec construction par délégation
	{ cerr << "Construction Rectangle" ; }
	
//Construction 
//qui prend en paramètre un flux
Rectangle::Rectangle(istream & is)
	:Forme(is), largeur(0), hauteur(0)
	{ is >> largeur >> hauteur ;cout << "construction copie rect "; }

//Destructeur	
Rectangle::~Rectangle()
	{ cerr << "Destructeur rectangle" ; }
	
void Rectangle::dessiner(EZWindow & win, bool isActive) const
	{
		Forme::dessiner(win, isActive) ;
		if(!getRemplissage())
		//Les coordonnées du rectangle sont passées en paramètres dans 
		//la méthode EZWindow::drawRectangle afin de dessiner les traits du rectangle.		
			win.drawRectangle( getAncre().getX(), getAncre().getY(), getAncre().getX()+largeur, getAncre().getY()+hauteur) ;
		else
		//Les coordonnées du rectangle sont passées en paramètre dans 
		// la méthode EZWindow::fillRectangle afin de dessiner un rectangle plein.
			win.fillRectangle( getAncre().getX(), getAncre().getY(), getAncre().getX()+largeur, getAncre().getY()+hauteur) ;
		win.setThick(1);
		} 
	
//Permet d'écrire le nom de la forme ainsi que ses attributs.
//Cette fonction prend en paramètre un flux dans lequel on va injecter le nom
//et les attributs de la forme.	
void Rectangle::ecrire(ostream & os) const
{ os << "Rectangle "; Forme::ecrire(os); os << largeur << " " << hauteur << " "; }
		
	
