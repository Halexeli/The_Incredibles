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
    Ellipse(Point * const p, const double a, const double b, const double angle);
    ~Ellipse(){};
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
    bool const contientPoint(const Point& point) override;
    void const afficherInfos() override;
};