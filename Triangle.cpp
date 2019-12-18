#include <cmath>
#include "Triangle.hpp"

using namespace std;

//Implantation de la classe Triangle

//Constructeur
//qui prend en paramètre sept entier
//pour la couleur et les trois ancres
Triangle::Triangle(ulong _couleur, uint _x, uint _y, uint _n, uint _a, uint _s, uint _z)
		: Forme(_couleur, _x, _y), n(_n), a(_a), s(_s), z(_z), ancre1(ancre.getX()+_n, ancre.getY()+_a), ancre2(ancre.getX()+_s, ancre.getY()+_z) //Liste d'initialisation avec construction par délégation
		{
    ancre1Selected= false;
    ancre2Selected= false;
}

//Constructeur à partir d'un flux
Triangle::Triangle(istream &is)
		: Forme(is), n(0), a(0), s(0), z(0), ancre1(0,0), ancre2(0,0)
		{ is >> n >> a >> s >> z >> ancre1 >> ancre2; }

//Destructeur
Triangle::~Triangle() 
{}

//Retourne le périmètre
double Triangle::perimetre()const {
    double cote1, cote2, cote3;
    cote1= sqrt(pow((n-ancre.getX()),2)+pow((a-ancre.getY()),2));
    cote2= sqrt(pow((s-ancre.getX()),2)+pow((z-ancre.getY()),2));
    cote3= sqrt(pow((n-s),2)+pow((a-z),2));
    return (cote1+cote2+cote3);
}

//Permet d'écrire le nom de la forme ainsi que ses attributs.
//Cette fonction prend en paramètre un flux dans lequel on va injecter le nom
//et les attributs de la forme.
void Triangle::ecrire(ostream &os) const {
    os << "Triangle" ;
    Forme::ecrire(os) ;
    os << " " <<n << " " << a << " " << s << " " << z << " " << ancre1 << " " << ancre2;
}

void Triangle::dessiner(EZWindow &w, bool isActive) const {
    Forme::dessiner (w, isActive);
    const Point& ancre= getAncre();
    if(!getRemplissage())
        w.drawTriangle(ancre.getX(),ancre.getY(), ancre.getX()+n, ancre.getY()+a, ancre.getX()+s, ancre.getY()+z);
    else
        w.fillTriangle(ancre.getX(),ancre.getY(), ancre.getX()+n, ancre.getY()+a, ancre.getX()+s, ancre.getY()+z);
    w.setColor(ez_red);
    ancre1.dessiner(w,isActive);
    ancre2.dessiner(w,isActive);
    w.setColor(couleur);
    w.setThick();
}

bool Triangle::isOver(uint _x, uint _y){
	 if(ancre1.isOver(_x, _y)) {
                ancre1Selected= true;
                ancre2Selected= false;
                return ancre1.isOver(_x, _y);
            }
            if(ancre2.isOver(_x, _y)) {
                ancre2Selected= true;  
                ancre1Selected= false;
                return ancre2.isOver(_x, _y);
            }
            ancre1Selected= false;
            ancre2Selected= false;
            return ancre.isOver(_x, _y);
}
void Triangle::setAncre(uint _x, uint _y){
            if(ancre1Selected) {
                n= _x-ancre.getX();
                a= _y-ancre.getY();
                ancre1.setXY(ancre.getX()+n,ancre.getY()+a);
            }
            if(ancre2Selected) {
                s= _x-ancre.getX();
                z= _y-ancre.getY();
                ancre2.setXY(ancre.getX()+s,ancre.getY()+z);
		ancre1Selected= false;
            }
            if(!ancre1Selected && !ancre2Selected) {
                Forme::setAncre(_x, _y);
                ancre1.setXY(ancre.getX()+n,ancre.getY()+a);
                ancre2.setXY(ancre.getX()+s,ancre.getY()+z);
            }
        }
