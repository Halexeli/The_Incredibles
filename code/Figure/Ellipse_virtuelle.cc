#include "Ellipse_virtuelle.hh"
#include "SFML/Graphics.hpp"
#include <cmath>

Ellipse_virtuelle::Ellipse_virtuelle() : Figure() {
    a = 0;
}

Ellipse_virtuelle::Ellipse_virtuelle(const Ellipse_virtuelle &p) : Figure(p) {
    a = p.a;
}

Ellipse_virtuelle::Ellipse_virtuelle(const Point& p, const double _a) : Figure(p) {
    a = _a;
}

// méthode de translation 
void Ellipse_virtuelle::translater(double dx, double dy) {
    centre.setX(centre.getX() + dx);
    centre.setY(centre.getY() + dy);
}

// ajuster la forme dans une fenêtre donnée 
void Ellipse_virtuelle::ajusterDansFenetre(int largeurFenetre, int hauteurFenetre) {
    if (centre.getX() + a > largeurFenetre) centre.setX(largeurFenetre - a);
    if (centre.getY() + a > hauteurFenetre) centre.setY(hauteurFenetre - a);
}


void Ellipse_virtuelle::afficherInfos() const {
    //faut ajouter ça
}