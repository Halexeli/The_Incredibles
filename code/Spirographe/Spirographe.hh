//test
//test
#pragma once 
#include <iostream>
#include "Figure/Figure.hh"
#include "Figure/Polyedre.hh"
#include "Figure/Ellipse.hh"

class Spirographe {

    protected:
        Ellipse_virtuelle &fixe;
        Cercle roulant;
        Point crayon;
        Polyedre_virtuel &contrainte;
        std::deque<float,float> to_draw;
    public:
        Spirographe();
        Spirographe(const Spirographe &s);
        Spirographe( Point crayon, Polyedre_virtuel &contrainte);
        ~Spirographe();
        void draw();
        void afficher();

};

