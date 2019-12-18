#include <iostream>
using namespace std ;
#include "Ellipse.hpp"

//Implantation de la classe Ellipse


//Constructeur
//qui prend en paramètre cinq entier
//pour la couleur, l'ancre, la demi-largeur et la demi-hauteur
Ellipse::Ellipse(ulong _couleur, uint _x, uint _y, uint _demiLargeur, uint _demiHauteur)
	: Forme(_couleur, _x, _y), demiLargeur(_demiLargeur), demiHauteur(_demiHauteur) //Liste d'initialisation avec construction par délégation
	{ cerr << "Construction ellipse" ; }
	
//Constructeur à partir d'un flux
Ellipse::Ellipse(istream & is)
	: Forme(is), demiLargeur(0), demiHauteur(0) //Liste d'initialisation avec construction par délégation
	{ is >> demiLargeur >> demiHauteur ; }
	
//Destructeur virtuel
Ellipse::~Ellipse()
{ cerr << "Destruction Ellipse" ; }

void Ellipse::dessiner(EZWindow & wdw, bool isActive) const
{ 

		Forme::dessiner(wdw, isActive) ;
		if(!getRemplissage())
		//Les coordonnées de l'ellipse sont passées en paramètres dans 
		//la méthode EZWindow::drawCircle afin de dessiner les traits de l'ellipse.
			wdw.drawCircle(getAncre().getX(), getAncre().getY(), getAncre().getX()+demiLargeur, getAncre().getY()+demiHauteur) ; 
		else
		//Les coordonnées de l'ellipse sont passées en paramètre dans 
		// la méthode EZWindow::fillCircle afin de dessiner une ellipse pleine.
			wdw.fillCircle(getAncre().getX(), getAncre().getY(), getAncre().getX()+demiLargeur, getAncre().getY()+demiHauteur) ; 
		wdw.setThick(1);
 }

//Permet d'écrire le nom de la forme ainsi que ses attributs.
//Cette fonction prend en paramètre un flux dans lequel on va injecter le nom
//et les attributs de la forme.
void Ellipse::ecrire(ostream & os) const
{ os << "Ellipse "; Forme::ecrire(os); os  << demiLargeur << " " << demiHauteur ; }
