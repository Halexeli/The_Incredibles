#pragma once

#include "Ellipse_virtuelle.hh"
//#include "SFML/Graphics.hpp"
#include "Point.hh"
#include <iostream>
#include <cmath>

class Cercle : public Ellipse_virtuelle {
public:
    // Constructeurs
    Cercle();
    Cercle(const Cercle& c);
    Cercle(const Point& centre, const double rayon);

    // Destructeur
    ~Cercle();

    // Méthodes spécifiques au cercle
    double diametre() const;
    double circonference() const;
    bool contientPoint(const Point& p) const;

    // Méthode d'affichage
    void afficher(Screen& window);

    // Méthode de redimensionnement
    void redimensionner(double facteur);

    // Méthode d'informations
    void afficherInfos() const;
};
