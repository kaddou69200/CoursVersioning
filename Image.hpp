#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <iostream>
using namespace std ;
#include "ez-draw++.hpp"
#include "Forme.hpp"





class Image : public Forme {
	private :
		EZImage madara;
		int spgX; //type d'entier qui permet de stocker l'angle 
		int spgY; //en haut a gauche de l'image rogner
		int largeur; //Type entier qui permet de stocker la largeur d'une image rogner
		int hauteur; //Type entier qui permet de stocker la hauteur d'une image rogner
		void ecrire(ostream & os) const override ; //permet d'écrire le nom de la forme ainsi que ses attributs.
		bool transp; //type booléen qui permet de gérer la transparence
		string files;//type string qui permet de stocker le lien répertoir de limage
		
	public :
		Image(ulong couleur, uint _x , uint _y,const char*_file) ; //Constructeur d'Image
		Image(ulong couleur, uint _x , uint _y,const char*_file, int _spgX, int _spgY, int largeur, int hauteur) ; //Constructeur d'Image avec les dimensions de l'image
		Image(istream & is) ; //Constructeur à partir d'un flux
		~Image() override; //Destructeur
		inline void setTransp() override {madara.setAlpha(!getTransp()); transp=!getTransp();}// set La transparence de l'image
		inline bool getTransp(){return transp;} //get la transparence de l'image
		void dessiner(EZWindow & , bool isActive = false) const ; //Permet de dessiner une image dans la fenetre
		inline double perimetre() const override { return 0 ; } 
		inline int getHauteur() const { return hauteur ; } //getter retournant la hauteur d'une image
		inline void setHauteur( int _hauteur) { hauteur = _hauteur ; } //setter donnant accès à la hauteur
		inline int getLargeur() const { return largeur ; } //getter retournant la largeur d'une image
		inline void setLargeur( int _largeur) { largeur = _largeur ; } //setter donnant accès à la largeur
		inline int getSpgX() const { return spgX;}
		inline void setSpgX(int _spgX){ spgX = _spgX; }
		inline int getSpgY() const { return spgY;}
		inline void setSpgY(int _spgY){ spgY = _spgY; }
		// void setAncre(uint _x, uint _y) override ;
        // bool isOver(uint _x, uint _y) override ;
};

#endif
