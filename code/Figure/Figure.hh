// classe abstraite pour toutes les formes géométriques
#pragma once
#include "Point.hh"
#include <iostream>
#include "../Affichage/Screen.hh"

class Figure{
    protected :
        Point centre; // centre de la figure
    public:
        Figure():centre(Point()){};
        Figure(const Point& p):centre(Point(p)){};
        Figure(const Figure& p):centre(p.centre){};
        const Point& getCentre() { return centre; }

        ~Figure(){};
        virtual void afficher(Screen &screen)=0;
};
