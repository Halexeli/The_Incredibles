// classe abstraite pour toutes les formes géométriques
#pragma once
#include "Point.hh"
#include <iostream>

class Figure{
    protected :
        Point centre; // centre de la figure
    public:
        Figure():centre(Point()){};
        Figure(const Point& p):centre(Point(p)){};
        Figure(const Figure& p):centre(p.centre){};
        const Point& getCentre() const { return centre; };

        ~Figure(){};
        virtual void afficher()=0;
};
