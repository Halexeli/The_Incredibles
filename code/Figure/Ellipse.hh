#pragma once
#include "Ellipse_virtuelle.hh"
#include <iostream>
#include "SFML/Graphics.hpp"

class Ellipse:Ellipse_virtuelle{
    private:
        double b; // demi petit axe
        double angle; // angle de rotation
    public:
        Ellipse();
        Ellipse(const Ellipse& p);
        Ellipse(const Point& p, const double a);
        double aire() const;
        double perimetre() const;
        void redimensionner(double facteurA, double facteurB);
        void pivoter(double angleSupplementaire);
        void afficher(sf::RenderWindow& window); 
        void afficher();
        void afficherInfos() const;
        ~Ellipse(){};
};



