#pragma once
#include "Point.hh"
#include <SFML/Graphics.hpp>
#include "../Affichage/Screen.hh"

class Figure {
protected:
    Point centre;
public:
    Figure() : centre(Point()) {}
    Figure(const Point& p) : centre(p) {}
    virtual ~Figure() {}
    
    Point getCentre() const { return centre; }
    virtual void afficher(Screen& window) = 0;
    virtual bool contientPoint(const Point& point) const = 0;
};