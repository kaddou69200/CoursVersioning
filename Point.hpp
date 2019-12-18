#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
using namespace std ;
#include "ez-draw++.hpp"


typedef unsigned int uint ;
typedef unsigned long int ulong ;

//Déclaration de la classe Point
class Point {
	//Données privées
	private :
		uint taille = 3 ; //Type entier non-signé qui représente la taille d'un point
		uint x, y ; //Type entier non-signé qui représentent les coordonnées x et y d'un point
	
	//Méthodes publiques	
	public :
		
		Point(uint x, uint y) ; //Constructeur de Point
		Point(const Point & origine) ; //Constructeur par copie
		Point(istream & is) ; //Constructeur à partir d'un flux
		~Point() ; //Destructeur
		inline uint getX() const { return x ; } //getter retournant la coordonnée x
		inline uint getY() const { return y ; } //getter retournant la coordonnée y
		inline void setXY(uint _x, uint _y) { x = _x ; y = _y ; } //setter permettant de paramétrer x et y
		bool isOver(uint x, uint y) ; //test de la selection avec la souris
		void dessiner(EZWindow & w, bool isActive = false) const ; //Permet de dessiner un point dans la fenetre
		friend ostream & operator<<(ostream & os, const Point & P) ; //operateur d'injection
		friend istream & operator>>(istream & is, Point & p); //oprérateur d'extraction
};

#endif
