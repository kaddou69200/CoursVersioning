#include <iostream>
using namespace std ;
#include "Point.hpp"

//Implantation de la classe Point

//Constructeur
//qui prend en paramètre des coordonnées x et y
Point::Point(uint _x, uint _y) //Liste d'initialisation
	: x(_x), y(_y)
	{}
	
//Constructeur par copie
//qui prend en paramètre une référence constante sur un Point	
Point::Point(const Point & orig)
	: x(orig.x), y(orig.y) //Liste d'initialisation
	{}

//Constructeur à partir d'un flux	
Point::Point(istream & is)
	: x(0), y(0) //Liste d'initialisation
	{ is >> *this ; }

//Destructeur	
Point::~Point()
	{}

bool Point::isOver(uint _x, uint _y)
{ 
	uint dx = ( x < _x ? _x-x : x - _x ) ;
	uint dy = ( y < _y ? _y - y : y - _y ) ;
	
	return (dx<=taille && dy<=taille) ;
}


void Point::dessiner(EZWindow & window, bool isActive) const
{
	if (isActive)
		//Les coordonnées du point sont passées en paramètre dans 
		// la méthode EZWindow::fillRectangle afin de dessiner un point rempli.
		window.fillRectangle(x-taille, y-taille, x+taille, y+taille) ;
	else
		//Les coordonnées du point sont passées en paramètres dans 
		//la méthode EZWindow::drawRectangle afin de dessiner les traits du point.
		window.drawRectangle(x-taille, y-taille, x+taille, y+taille) ;
}

//Opérateur d'injection qui permet d'écrire dans un flux les coordonnées d'un point passé en paramètre
ostream & operator<<(ostream& os, const Point& p)
{ os << p.x << " " << p.y ; return os ; }

//Opérateur d'extraction qui permet d'extraire d'un flux les coordonnées d'un point
istream & operator>>(istream & is, Point & p)
{ is >> p.x >> p.y ; return is ; }
