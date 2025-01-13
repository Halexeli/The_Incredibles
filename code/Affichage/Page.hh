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
    //id de la page
    static int it;
    const int id; 
    //Le fond de la page (pour que les spirographe soit bien dans un endroit)
    std::vector <Polyedre_irregulier *> Fond;
    //Les boutons nécessaires
    std::vector <Bouton*> List_Bouton;
    //Les textes nécessaires
    std::vector <Texte*> List_string;
    public:
    Page():id(it){it++;};
    Page(const Page &p):id(p.id),Fond(p.Fond),List_Bouton(p.List_Bouton),List_string(p.List_string){};
    ~Page(){};
    int const get_id(){return(id);};
    void creer_fond(std::vector <Polyedre_irregulier*> Fond);
    void operator+=( Bouton * adding){List_Bouton.push_back(adding);};
    void operator+=( Texte * adding){List_string.push_back(adding);};
    void draw(Screen &screen);
    //Le fond de la page (pour que les spirographe soit bien dans un endroit)
    std::vector <Polyedre_irregulier *> const get_Fond(){return(Fond);};
    //Les boutons nécessaires
    std::vector <Bouton*> const get_List_Bouton(){return(List_Bouton);};
    //Les textes nécessaires
    std::vector <Texte*> const get_List_string(){return(List_string);};
};