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
    void redimensionner(double facteurA, double facteurB);
    void redimensionner(double facteur) override;
    void pivoter(double angleSupplementaire);
    void afficher(Screen& window) override;
    bool contientPoint(const Point& point) const override;
    void afficherInfos() const override;
};