#pragma once
#include <iostream>
#include "Bouton.hh"
#include "Screen.hh"
#include "SFML/Graphics.hpp"
#include "../Figure/Polyedre.hh"
#include "../Figure/Figure.hh"
#include "../Spirographe/Spirographe.hh"

class Page{
    private:
    static int it;
    const int id; 
    std::vector <Polyedre_irregulier *> Formes_irr;
    std::vector <Polyedre_regulier *> Formes_r;
    std::vector <Spirographe *> Spiro;
    std::vector <Polyedre_regulier *> Fond;
    std::vector <Bouton*> List_Bouton;
    std::vector <Texte*> List_string;
    public:
    Page():id(it){it++;};
    Page(const Page &p):id(id),Formes_irr(p.Formes_irr),Formes_r(p.Formes_r),Spiro(p.Spiro),Fond(p.Fond),List_Bouton(p.List_Bouton),List_string(p.List_string){};
    ~Page(){};
    void creer_fond(std::vector <Polyedre_regulier*> Fond);
    void operator+=(Polyedre_irregulier * adding){Formes_irr.push_back(adding);};void operator+=(Polyedre_irregulier * adding){Formes_irr.push_back(adding);};
    void operator+=(Polyedre_regulier * adding){Formes_r.push_back(adding);};
    void operator+=( Spirographe* adding){Spiro.push_back(adding);};
    void operator+=( Bouton * adding){List_Bouton.push_back(adding);};
    void operator+=( Texte * adding){List_string.push_back(adding);};
    void draw(Screen &screen);
};