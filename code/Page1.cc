#include <SFML/Graphics.hpp>
#include "Affichage/Page.hh"  
#include "Affichage/Screen.hh"
#include "Spirographe/Spirographe.hh"
#include "Affichage/Bouton.hh"
Page *Page1(){
    Page *page= new Page();
    //boutons
    Bouton *NouvelleFigure = new Bouton(15, 15, 30, 30, "+");
    *page += NouvelleFigure;
    std::vector <Polyedre_regulier> *Fond;
    Point *P1=new Point(480,50);
    Polyedre_irregulier *Forme1= new Polyedre_regulier(*P1,4,);
    page->creer_fond();
    return(0);
}