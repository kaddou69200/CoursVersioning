#ifndef POLYGONE_HPP
#define POLYGONE_HPP

#include <iostream>
#include <vector>
#include <cmath>
using namespace std ;
#include "ez-draw++.hpp"
#include "Forme.hpp"

class Polygone : public Forme {
	private :
		uint nbPoint ; //Permet de stocker le nombre de point dans une forme
		vector<int> tabX; //permet de stocker tout les points X de la forme
		vector<int> tabY; //permet de stocker tout les points Y de la forme
		void ecrire(ostream & os) const override ; 
		vector<int>tabCote;// permet de stocker la longueur de tout les côté de la forme
		
	public :
		Polygone(ulong couleur, uint nbPoint, vector<int> _tabX, vector<int> _tabY) ;
		Polygone(istream & is) ;
		~Polygone() override;
		void dessiner(EZWindow & fenetre, bool isActive = false) const ;
		inline double perimetre() const override {double per=0 ;for (uint i =0; i<=nbPoint;i++) per += tabCote[i]; return per ; }//calcule le périmettre (non fonctionnel)
		inline uint getTabX(uint i) const { return tabX[i] ; }
		inline uint getTabY(uint i) const { return tabY[i] ; }
		inline void setTabX( uint _x) { tabX.push_back(_x) ; } // ajoute une ligne
		inline void setTabY( uint _y) { tabX.push_back(_y) ; } // avec une nouvelle donnée
		void setTabCote(){for (uint i = 0 ; i<=nbPoint;i++) tabCote.push_back(sqrt(pow(getTabX(i)-getTabX(i+1),2)+pow(getTabY(i)-getTabY(i+1),2))); tabCote.push_back(sqrt(pow(getTabX(0)-getTabX(nbPoint+1),2)+pow(getTabY(0)-getTabY(nbPoint+1),2))); } //calcul et stockage des côtés
};

#endif
