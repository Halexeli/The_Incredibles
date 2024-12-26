#pragma once
#include "Figure.hh"
#include <iostream>
#include <stack>
#include <vector>
#include "../Affichage/Screen.hh"

class Polyedre_virtuel:Figure{
    protected:
        int sommets;
    public:
        Polyedre_virtuel();
        Polyedre_virtuel(const Polyedre_virtuel& p);
        Polyedre_virtuel(const Point& p,int sommets);
        ~Polyedre_virtuel();
};

class Polyedre_regulier:Figure{
    private:
        int sommets;
        double cote;
        double angle;
    public:
        Polyedre_regulier();
        Polyedre_regulier(const Polyedre_regulier& p);
        Polyedre_regulier(const Point& p,int sommets,int rayon,double angle);
        ~Polyedre_regulier();
        void afficher(Screen &screen);
};

class Polyedre_irregulier:Figure{
    private:
        int sommets;
        std::stack<std::vector<double,double>> list_sommets;
    public:
        Polyedre_irregulier();
        Polyedre_irregulier(const Polyedre_irregulier& p);
        Polyedre_irregulier(const Point& p,int sommets,std::stack<std::vector<double,double>> list_sommets);
        ~Polyedre_irregulier();
        void afficher(Screen &screen);
};
