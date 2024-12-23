//test
//test
#pragma once 
#include <iostream>
#include "Figure/Figure.hh"
#include "Figure/Polyedre.hh"
#include "Figure/Ellipse.hh"

class Spirographe {

    protected:
        const static float dt=0.01;
        float v;
        Ellipse_virtuelle &fixe;
        Cercle roulant;
        Point crayon;
        Polyedre_virtuel &contrainte;
        std::vector<float,float> position[1];
        std::deque<float,float> to_draw;
    public:
        Spirographe();
        Spirographe(const Spirographe &s);
        Spirographe( Point crayon, Polyedre_virtuel &contrainte);
        ~Spirographe();
        void draw();
        void update();
        std::deque<float,float> get_to_draw();
};

