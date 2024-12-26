#pragma once
#include "Ellipse_virtuelle.hh"
#include <iostream>
#include "SFML/Graphics.hpp"

class Ellipse:public Ellipse_virtuelle{
    private:
        double b; // demi petit axe
        double angle; // angle de rotation
    public:
        Ellipse();
        Ellipse(const Ellipse& p);
        Ellipse(const Point& p, const double a, const double b, const double angle);
        // Getters et Setters
        double getB() const;
        void setB(double _b);
        double getAngle() const;
        void setAngle(double _angle);
        // Méthodes
        double aire() const;
        double perimetre() const;
        void redimensionner(double facteurA, double facteurB);
        void pivoter(double angleSupplementaire);
        void afficher(sf::RenderWindow& window); 
        void afficherInfos() const;
        ~Ellipse(){};
};



