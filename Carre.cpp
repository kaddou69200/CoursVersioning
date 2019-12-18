#include <iostream>
using namespace std ;
#include "ez-draw++.hpp"
#include "Carre.hpp"

//Implantation de la classe Carre

//Constructeur
Carre::Carre(ulong _couleur, uint _x, uint _y, uint _cote)
	: Forme(_couleur, _x, _y), cote(_cote) // Liste d'initialisation
						    // On utilise ici une délégation de construction
	{ cerr << "Construction Carre" ; }

//Constructeur à partir d'un flux	
//Il prend en paramètre un flux.
Carre::Carre(istream & is)
	: Forme(is), cote(0) //Liste d'intitialisation
	{ is >> cote ; }
	
//Destructeur	
Carre::~Carre()
	{ cerr << "Destructeur carre" ; }

//Cette fonction permet de dessiner un carre.	
void Carre::dessiner(EZWindow & windo, bool isActive) const
{	
  		Forme::dessiner(windo, isActive) ; 
		
		if(!getRemplissage())
		//Les coordonnées du carré sont passées en paramètres dans 
		//la méthode EZWindow::drawRectangle afin de dessiner les traits du carre.
			windo.drawRectangle( getAncre().getX(), getAncre().getY(), getAncre().getX()+getCote(), getAncre().getY()+getCote()) ; 
		else
		//Les coordonnées du carré sont passées en paramètre dans 
		// la méthode EZWindow::fillRectangle afin de dessiner un carré plein.
			windo.fillRectangle( getAncre().getX(), getAncre().getY(), getAncre().getX()+getCote(), getAncre().getY()+getCote()) ; 
		windo.setThick(1); //L'épaisseur d'un trait est égal à 1	
}

//Permet d'écrire le nom de la forme ainsi que ses attributs.
//Cette fonction prend en paramètre un flux dans lequel on va injecter le nom
//et les attributs de la forme.		
void Carre::ecrire(ostream & os) const
{ os << "Carre " ; Forme::ecrire(os); os << cote; }
