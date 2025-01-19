#pragma once
#include "Point.hh"
#include <SFML/Graphics.hpp>
#include "../Affichage/Screen.hh"

class Figure {
protected:
    Point * centre;
    sf::Color _color;
public:
    Figure():centre(nullptr) {}
    Figure( Point *const p) : centre(p) {}
    virtual ~Figure() {}
    
    const Point * getCentre() const { return centre; }
    void setCentre(const Point& p) { *centre = p; }
    void setFillColor(sf::Color color) { _color = color; }
    virtual void afficher(Screen& window) = 0;
    virtual bool const contientPoint(const Point& point) = 0;
};