#include"Spirographe.hh"
#include <iostream>
//constructeurs:
Spirographe::Spirographe():fixe(),roulant(),crayon(),contrainte()
{
}

Spirographe::Spirographe(const Spirographe &s):fixe(s.fixe),roulant(s.roulant),crayon(s.crayon),contrainte(s.contrainte)
{
}

Spirographe::Spirographe(Point _crayon, Polyedre_virtuel &_contrainte):fixe(),roulant(),crayon(_crayon),contrainte(_contrainte)
{
}
//destructeur
Spirographe::~Spirographe()
{
}
//affichage
void Spirographe::afficher()
{
    std::cout<<"méthode a implementer"<<std::endl;
}