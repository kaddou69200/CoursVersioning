#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
using namespace std;
#include "Forme.hpp"

//Déclaration de la classe Triangle qui hérite de la classe Forme
class Triangle : public Forme {
    //Données et méthode privées
    private:
            
       uint n; //Type entier non-signé permettant de représenter la coordonnée x de l'ancre1
	uint a; //Type entier non-signé permettant de représenter la coordonnée y de l'ancre1
	uint s; //Type entier non-signé permettant de représenter la coordonnée x de l'ancre2
	uint z; //Type entier non-signé permettant de représenter la coordonnée y de l'ancre2
       Point ancre1; //Type Pont permettant de représenter l'ancre du deuxième point
	Point ancre2; //Type Pont permettant de représenter l'ancre du troisième point
	bool ancre1Selected, ancre2Selected; //Type booléen permettant de savoir si les points sont sélectionnés
       void ecrire(std::ostream &os) const override; //permet d'écrire le nom de la forme ainsi que ses attributs. 
        
    //Méthodes publiques	           
    public:
            
        Triangle(ulong _couleur, uint _x, uint _y, uint _n, uint _a, uint _s, uint _z); //Constructeur de Triangle
        Triangle(istream &is); //Constructeur qui prend en paramètre un flux
        ~Triangle() override; //Destructeur virtuel
        void dessiner(EZWindow& f, bool isActive= false) const override; //Permet de dessiner un triangle dans la fenêtre
        inline uint getN()const { return n;} //getter retournant la coordonnée x de l'ancre1
        inline void setN(uint _n) {n= _n;} //setter donnant l'accès à la coordonnée x de l'ancre1
        inline uint getA()const {return a;} //getter retournant la coordonnée y de l'ancre1
        inline void setA(uint _a) {a = _a;} //setter donnant l'accès à la coordonnée y de l'ancre1
        inline uint getS()const {return s;} //getter retournant la coordonnée x de l'ancre2
        inline void setS(uint _s) {s = _s;} //setter donnant l'accès à la coordonnée x de l'ancre2
        inline uint getZ()const {return z;} //getter retournant la coordonnée y de l'ancre2
        inline void setZ(uint _z) {z = _z;} //setter donnant l'accès à la coordonnée y de l'ancre2
        double perimetre()const override;   //retourne le périmètre du triangle
        void setAncre(uint _x, uint _y) override ;
        bool isOver(uint _x, uint _y) override ;
};

#endif 

