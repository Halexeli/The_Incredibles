#pragma once
#include "Ellipse_virtuelle.hh"
#include "SFML/Graphics.hpp"
#include "Point.hh"
#include <iostream>
#include <cmath>

class Cercle : public Ellipse_virtuelle {
public:
    Cercle();
    Cercle(const Cercle& c);
    Cercle(const Point& centre, const double rayon);
    ~Cercle();

    double diametre() const;
    double circonference() const;
    bool contientPoint(const Point& p) const override;

    using Ellipse_virtuelle::afficher;
    void afficher(sf::RenderWindow& window) override;

    using Ellipse_virtuelle::redimensionner;
    void redimensionner(double facteur) override;

    void afficherInfos() const override;
};