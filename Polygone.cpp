#include <iostream>
using namespace std ;
#include "ez-draw++.hpp"
#include "Polygone.hpp"

Polygone::Polygone(ulong _couleur, uint _nbPoint, vector<int> _tabX, vector<int> _tabY)
	: Forme(_couleur, _tabX[0], _tabY[0]) , nbPoint(_nbPoint), tabX(_tabX) , tabY(_tabY)
	{ cerr << "Construction Polygone" ; setTabCote();	}
	
Polygone::Polygone(istream & is)//construction à partire d'un flux (non fonctionnel)
	: Forme(is), nbPoint(0), tabX(0), tabY(0)
	{ 
		is >> nbPoint;
		uint k;
		uint l;
		setTabX(getAncre().getX() );
		setTabY(getAncre().getY() );
		for (uint i=1; i<=nbPoint; i++)
		{
			is >> k >> l;
			setTabX(k);
			setTabY(l);
		}
	}
	
Polygone::~Polygone()
	{ cerr << "Destructeur Polygone" ; }
	
void Polygone::dessiner(EZWindow & windo, bool isActive) const
{	
  		Forme::dessiner(windo, isActive) ;
		//Mise en forme du polygone avec ou sans remplissage fonctionnel jusqu'a 5 point en utilisant des triangles remplis
		//Forme non rempli
		if(!getRemplissage()){
			windo.drawLine( getAncre().getX(), getAncre().getY(), getAncre().getX()+getTabX(1), getAncre().getY()+getTabY(1)) ;
			for(uint i = 2; i < nbPoint+1; i++){
				windo.drawLine( getAncre().getX()+getTabX(i-1), getAncre().getY()+getTabY(i-1), getAncre().getX()+ getTabX(i), getAncre().getY()+ getTabY(i));
			}
			windo.drawLine(getAncre().getX(), getAncre().getY(),getAncre().getX()+getTabX(nbPoint-1),getAncre().getY()+getTabY(nbPoint-1));
		}//Forme rempli		
		else{
			windo.fillTriangle( getAncre().getX()+getTabX(nbPoint-1), getAncre().getY()+getTabY(nbPoint-1), getAncre().getX(), getAncre().getY(), getAncre().getX()+ getTabX(1), getAncre().getY()+ getTabY(1)) ;
			for (uint i=2;  i < nbPoint-1; i++)
				windo.fillTriangle( getAncre().getX()+getTabX(i-1), getAncre().getY()+getTabY(i-1), getAncre().getX()+ getTabX(i), getAncre().getY()+ getTabY(i), getAncre().getX()+ getTabX(i+1), getAncre().getY()+ getTabY(i+1)) ;
			windo.fillTriangle( getAncre().getX()+getTabX(nbPoint-1), getAncre().getY()+getTabY(nbPoint-1), getAncre().getX()+ getTabX(1), getAncre().getY()+ getTabY(1), getAncre().getX()+ getTabX(2), getAncre().getY()+ getTabY(2)) ;
			}
		
		windo.setThick(1);		}

		
void Polygone::ecrire(ostream & os) const 
{ os << "Polygone " ; Forme::ecrire(os); os << nbPoint ;for (uint i=1; i<nbPoint; i++){ os << " " <<tabX[i] << " " << tabY[i];}}
