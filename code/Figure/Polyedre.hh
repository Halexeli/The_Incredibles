#pragma once
#include "Point.hh"
#include "Figure.hh"
#include <iostream>
#include <vector>
#include <utility>
#include <SFML/Graphics.hpp>
#include <math.h>

class Polyedre_virtuel : public Figure {
protected:
    int sommets;
public:
    Polyedre_virtuel();
    Polyedre_virtuel(const Polyedre_virtuel& p);
    Polyedre_virtuel(const Point& p, int sommets);
    virtual ~Polyedre_virtuel();
    virtual void afficher(Screen& window) = 0;
    virtual bool const contientPoint(const Point& point) = 0;
};

class Polyedre_regulier : public Polyedre_virtuel {
private:
    double cote;
    double angle;
public:
    Polyedre_regulier();
    Polyedre_regulier(const Polyedre_regulier& p);
    Polyedre_regulier(const Point& p, int sommets, double cote, double angle);
    ~Polyedre_regulier();
    void afficher(Screen& window) override;
    bool const contientPoint(const Point& point) override;
};

class Polyedre_irregulier : public Polyedre_virtuel {
private:
    std::vector<Point>  list_sommets;
public:
    Polyedre_irregulier();
    Polyedre_irregulier(const Polyedre_irregulier& p);
    Polyedre_irregulier(const Point& p, int sommets, std::vector<Point>  list_sommets);
    ~Polyedre_irregulier();
    void afficher(Screen& window) override;
    bool const contientPoint(const Point& point) override;
};