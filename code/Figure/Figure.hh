#pragma once
#include "Point.hh"
#include <SFML/Graphics.hpp>
#include "../Affichage/Screen.hh"

class Figure {
protected:
    Point centre;
    sf::Color _color;
public:
    Figure() : centre(Point()) {}
    Figure(const Point& p) : centre(p) {}
    virtual ~Figure() {}
    
    const Point * getCentre() { return &centre; }
    void setCentre(const Point& p) { centre = p; }
    void setFillColor(sf::Color color) { _color = color; }
    virtual void afficher(Screen& window) = 0;
    virtual bool contientPoint(const Point& point) const = 0;
};