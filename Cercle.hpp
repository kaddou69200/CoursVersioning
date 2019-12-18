#ifndef CERCLE_HPP
#define CERCLE_HPP

#include <iostream>
using namespace std ;
#include "Forme.hpp"

//Déclaration de la classe Cercle
//Elle hérite de la classe Forme
class Cercle : public Forme {
	//donnée et méthode privée
	private :
		uint rayon ; //Type entier non-signé permettant de représenter le rayon
		void ecrire(ostream & os) const override ; //permet d'écrire le nom de la forme ainsi que ses attributs. 
		
	public :
		Cercle(ulong couleur, uint x, uint y, uint rayon) ; //Constructeur de Cercle.
		Cercle(istream & is) ; //Constructeur à partir d'un flux
		~Cercle() override; //Destructeur virtuel
		void dessiner(EZWindow & fenetre, bool isActive = false) const ; //Permet de dessiner un cercle dans la fenêtre
		inline double perimetre() const override { return (2*3.14159*rayon) ; } //Retourne le périmètre d'un cercle
		inline uint getRayon() const { return rayon ; } //getter retournant le rayon
		inline void setRayon(uint _rayon) { rayon = _rayon ; } //setter donnant accès au rayon
};

#endif
