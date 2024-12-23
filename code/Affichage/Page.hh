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
    std::vector <Figure *> Formes;
    std::vector <Spirographe *> Spiro;
    std::vector <Polyedre_regulier *> Fond;
    std::vector <Bouton*> List_Bouton;
    std::vector <Texte*> List_string;
    public:
    Page():id(it){it++;};
    Page(const Page &p):id(id),Formes(p.Formes),Spiro(p.Spiro),Fond(p.Fond),List_Bouton(p.List_Bouton),List_string(p.List_string){};
    ~Page(){};
    void operator+=(Figure * adding){Formes.push_back(adding);};
    void operator+=( Spirographe* adding){Spiro.push_back(adding);};
    void operator+=( Polyedre_regulier * adding){Fond.push_back(adding);};
    void operator+=( Bouton * adding){List_Bouton.push_back(adding);};
    void operator+=( Texte * adding){List_string.push_back(adding);};
    void draw(Screen &screen);
};