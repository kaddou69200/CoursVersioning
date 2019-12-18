#include <iostream>
using namespace std ;
#include "Cercle.hpp"

//Implantation de la classe Cercle

//Constructeur
//qui prend en paramètre quatre entiers pour
//la couleur, l'ancre et le rayon
Cercle::Cercle(ulong _couleur, uint _x, uint _y, uint _rayon)
	: Forme(_couleur, _x, _y), rayon(_rayon) //Liste d'initialisation avec construction par délégation
	{ cerr << "Construction Cercle" ; }

//Constructeur qui prend en paramètre un flux	
Cercle::Cercle(istream & is)
	: Forme(is), rayon(0) //Liste d'initialisation avec construction par délégation
	{ is >> rayon ; }
	
//Destructeur
Cercle::~Cercle() 
{ cerr << "Destruction de Cercle" ; }

//Cette fonction permet de dessiner un cercle
void Cercle::dessiner(EZWindow & wdw, bool isActive) const
{
		Forme::dessiner(wdw, isActive) ;
		const Point & ancre = getAncre() ; 
		
		if(!getRemplissage())
		//Les coordonnées du cercle sont passées en paramètres dans 
		//la méthode EZWindow::drawCircle afin de dessiner les traits du cercle.
			wdw.drawCircle(getAncre().getX(), getAncre().getY(), getAncre().getX()+getRayon(), getAncre().getY()+getRayon()) ; 
		else
		//Les coordonnées du cercle sont passées en paramètre dans 
		// la méthode EZWindow::fillCircle afin de dessiner un cercle plein.
			wdw.fillCircle(getAncre().getX(), getAncre().getY(), getAncre().getX()+getRayon(), getAncre().getY()+getRayon()) ; 
		wdw.setThick(1); //L'épaisseur d'un trait est égal à 1.
}

//Permet d'écrire le nom de la forme ainsi que ses attributs.
//Cette fonction prend en paramètre un flux dans lequel on va injecter le nom
//et les attributs de la forme.
void Cercle::ecrire(ostream & os) const
{ os << "Cercle " ; Forme::ecrire(os); os <<  rayon; }
