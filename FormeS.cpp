#include <iostream>
using namespace std ;

#include "FormeS.hpp"

//Implantation de la classe FormeS

//Constructeur
//qui prend en paramètrela taille
FormeS::FormeS(size_t taille)
	:maxformes(taille), nbformes(0), formes(nullptr) //liste d'initialisation
	{ formes = new Forme * [maxformes] ; } //On crée le tableau

//Destructeur	
FormeS::~FormeS() 
{ for(size_t i = 0 ; i < nbformes ; i++)
		delete formes[i] ; //On vide le tableau
	
	delete [] formes ; //On supprime le tableau
}

void FormeS::ajouter(Forme * forme)
{
	if (nbformes+1 > maxformes)
		throw std::runtime_error("Trop de formes") ; //Erreur: le tableau est plein
	
	formes[nbformes++] = forme ; //le pointeur sur Forme passé en paramètre est ajouté dans le tableau
}

void FormeS::dessiner(EZWindow & win) const
{ for(size_t i = 0 ; i < nbformes ; ++i)
	formes[i] -> dessiner(win) ;  //On dessine dans la fenêtre les formes présentent dans le tableau
}

Forme * FormeS::isOver(uint x, uint y)
{
	for(size_t i = 0 ; i < nbformes ; ++i)
		if (formes[i] -> isOver(x, y))
			return formes[i] ; 
		
	return nullptr ;
}

ostream & operator<<(ostream & os, FormeS formes)
{ os << formes ; return os ; } 

void FormeS::charger(istream & is)
{
	for(size_t i = 0 ; i<nbformes ; i++)
		delete formes[i] ; //On vide le tableau
	
	nbformes = 0 ; //On ré-initialise le nombre de forme
	size_t num ;
	is >> num ;
	
	if (num <= maxformes)
		for(size_t i = 0 ; i < num ; i++)
			ajouter(formes[i]->Forme::charger(is)) ; //On ajoute les nouvelles formes dans le tableau
	else
		throw runtime_error("Trop de formes") ;
}

void FormeS::sauver(ostream & os) 
{
	os << nbformes << endl;
	for(size_t i=0; i<nbformes; i++){
		formes[i]->ecrire(os); //Ecrit dans le flux les formes présentent dans le tableau
		os << endl;
	}
		
}
