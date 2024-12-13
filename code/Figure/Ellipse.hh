#pragma once
#include "Figure.hh"
#include <iostream>
#include "SFML/Graphics.hpp"

class Ellipse_virtuelle:Figure{
    //x²+y²=a
    protected:
        double a;
    public:
        Ellipse_virtuelle();
        Ellipse_virtuelle(const Ellipse_virtuelle& p);
        Ellipse_virtuelle(const Point& p, const double a);
        ~Ellipse_virtuelle(){};
        virtual void afficher()=0;

};

class Ellipse:Ellipse_virtuelle{
    private:
        double b;
        double angle;
    public:
        Ellipse();
        Ellipse(const Ellipse& p);
        Ellipse(const Point& p, const double a);
        ~Ellipse(){};
        virtual void afficher()=0;
};

class Cercle:Ellipse_virtuelle{
    public:
        Cercle();
        Cercle(const Cercle& p);
        Cercle(const Point& p,const double a);
        ~Cercle(){};
        void afficher(sf::CircleShape &shape);
        void afficher(){};

};

