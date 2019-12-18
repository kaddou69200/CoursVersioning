#include <iostream>
using namespace std ;
#include "ez-draw++.hpp"
#include "Image.hpp"

//Implantation de la classe Image

//Constructeur d'une image complète 
Image::Image(ulong _couleur, uint _x , uint _y,const char*  _file)
	: Forme(_couleur, _x, _y),madara(_file), spgX(0),spgY(0), largeur(0),hauteur(0),transp(true),files(_file)
	{ cerr << "Construction Image" << endl ; }

//Constructeur	d'une image rogner
Image::Image(ulong _couleur, uint _x , uint _y,const char*_file, int _spgX, int _spgY, int _largeur, int _hauteur) 
	:Forme(_couleur, _x, _y),madara(_file), spgX(_spgX),spgY(_spgY), largeur(_largeur),hauteur(_hauteur),transp(true),files(_file)
{
	cout << "Construction Image avec taille " << endl;
}

//Constructeur à partir d'un flux
Image::Image(istream & is)
	: Forme(is), madara(largeur,hauteur),spgX(0),spgY(0),largeur(0), hauteur(0),files("")
	{  
		is >> spgX >> spgY >> largeur >> hauteur >> files ;
		cout <<" on commence la copie " << files;
		const char * file = files.c_str();
		madara=EZImage(file);
	}
	
//Destructeur	
Image::~Image()
	{ cerr << "Destructeur Image" ; }
	
void Image::dessiner(EZWindow& win,bool isActive) const
{	
	
		if(getLargeur()==0)//Si la largeur du rognage = 0 car elle n'est pas toucher lorsque qu'on veut l'image en entière
		//Les coordonnées de l'image sont passées en paramètres dans 
		//la méthode EZWindow::paint afin de dessiner l'image complète	
			madara.paint(win,getAncre().getX(),getAncre().getY());
		else
			//affichage image rogner
			madara.paintSubimage(win,getAncre().getX(),getAncre().getY(),getSpgX(),getSpgY(),getLargeur(),getHauteur());
		Forme::dessiner(win, isActive) ;		
		}

//Permet d'écrire le nom de la forme ainsi que ses attributs.
//Cette fonction prend en paramètre un flux dans lequel on va injecter le nom
//et les attributs de la forme.		
void Image::ecrire(ostream & os) const
{ os << "Image "; Forme::ecrire(os); os  << " " << spgX << " " <<spgY<< " " <<largeur<< " " << hauteur  << files; }

