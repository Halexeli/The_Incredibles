#pragma once
#include "Ellipse_virtuelle.hh"
#include <cmath>
#include "SFML/Graphics.hpp"

class Ellipse : public Ellipse_virtuelle {
private:
    double b;
    double angle;
public:
    Ellipse();
    Ellipse(const Ellipse& p);
    Ellipse(const Point& p, const double a, const double b, const double angle);

    double getB() const;
    void setB(double _b);
    double getAngle() const;
    void setAngle(double _angle);

    double aire() const;
    double perimetre() const;
    //nb: 'using' permet de réutiliser une méthode de la classe mère
    using Ellipse_virtuelle::redimensionner;
    void redimensionner(double facteurA, double facteurB);
    void pivoter(double angleSupplementaire);

    using Ellipse_virtuelle::afficher;
    void afficher(sf::RenderWindow& window);

    void afficherInfos() const;
};