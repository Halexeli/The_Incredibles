#pragma once
#include "Figure.hh"
#include <iostream>
#include "SFML/Graphics.hpp"
#include <cmath>

class Ellipse_virtuelle : public Figure {
protected:
    double a; // demi grand axe
public:
    Ellipse_virtuelle();
    Ellipse_virtuelle(const Ellipse_virtuelle& p);
    Ellipse_virtuelle(const Point& p, const double a);
    // getters et setters 
    double get_a() const { return a; }
    void set_a(const double a) { this->a = a; }
    void translater(double dx, double dy);
    virtual void afficherInfos() const;
    virtual void afficher(Screen& window) = 0;
    virtual void redimensionner(double facteur) = 0;
    void ajusterDansFenetre(int largeurFenetre, int hauteurFenetre);
    ~Ellipse_virtuelle() = default;
};