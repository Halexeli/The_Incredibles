#include <SFML/Graphics.hpp>
#include "Affichage/Page.hh"  
#include "Affichage/Screen.hh"
#include "Spirographe/Spirographe.hh"
#include "Affichage/Bouton.hh"

Page *Page1(){
    Page *page= new Page();
    //boutons
    Bouton *NouvelleFigure = new Bouton(15, 15, 30, 30, "Nouvelle Figure");
    *page += NouvelleFigure;
    std::vector <Polyedre_irregulier *> Fond;
    Point *P1=new Point(480,50);
    std::vector<Point > list_sommets;
    //list_sommets.push_back();
    Polyedre_irregulier *Forme1= new Polyedre_irregulier(*P1,4,list_sommets);
    Fond.push_back(Forme1);
    page->creer_fond(Fond);
    return(page);
}

void del_page1(Page *page){
    std::vector <Bouton *> Bouton=page->get_List_Bouton();
    for(auto it:Bouton){
        delete it;
    } 
    std::vector <Polyedre_irregulier *> Fond=page->get_Fond();
    for(auto it:Fond){
        delete it->getCentre();
        delete it;
    }
    
}

Page *Page2(){
    Page *page= new Page();
    //boutons
    Bouton *Reguliere = new Bouton(45, 15, 30, 30, "régulière");
    *page += Reguliere;
    Bouton *Irreguliere = new Bouton(45, 60, 30, 30, "irrégulière");
    *page += Irreguliere;
    Bouton *sommetplus = new Bouton(45, 120, 30, 30, "+");
    *page += sommetplus;
    Bouton *sommetmoins = new Bouton(90, 120, 30, 30, "-");
    *page += sommetmoins;
    Texte *sommet_temp= new Texte(15,120,12,0xFF0000FF,"0");
    *page += sommet_temp;
    Texte *sommet= new Texte(105,120,12,0xFF0000FF,"nombre de sommets");
    *page += sommet;
    Bouton *xplus = new Bouton(45, 165, 30, 30, "x +");
    *page += xplus;
    Bouton *xmoins = new Bouton(90, 165, 30, 30, "x -");
    *page += xmoins;
    Texte *x_temp= new Texte(15,165,12,0xFF0000FF,"0");
    *page += x_temp;
    Bouton *yplus = new Bouton(120, 165, 30, 30, "y +");
    *page += yplus;
    Bouton *ymoins = new Bouton(165, 165, 30, 30, "y -");
    *page += ymoins;
    Texte *y_temp= new Texte(105,165,12,0xFF0000FF,"0");
    *page += y_temp;
    Bouton *tailleplus = new Bouton(45, 210, 30, 30, "+");
    *page += tailleplus;
    Bouton *taillemoins = new Bouton(90, 210, 30, 30, "-");
    *page += taillemoins;
    Texte *taille_temp= new Texte(15,210,12,0xFF0000FF,"0");
    *page += taille_temp;
    Texte *taille= new Texte(105,210,12,0xFF0000FF,"taille de la figure");
    *page += taille;
    Bouton *angleplus = new Bouton(45, 255, 30, 30, "+");
    *page += angleplus;
    Bouton *anglemoins = new Bouton(90, 255, 30, 30, "-");
    *page += anglemoins;
    Texte *angle_temp= new Texte(15,255,12,0xFF0000FF,"0");
    *page += angle_temp;
    Texte *angle= new Texte(105,255,12,0xFF0000FF,"angle de la figure\npar rapport a l'axe x");
    *page += angle;
    Bouton *ok= new Bouton(845, 15, 30, 30, "OK");
    *page += ok;
    std::vector <Polyedre_irregulier *> Fond;
    Point *P1=new Point(480,135);
    Point *P2=new Point(240,405);
    std::vector<Point > list_sommets1;
    std::vector<Point> list_sommets2;
    //list_sommets1.push_back();
    //list_sommets2.push_back();
    Polyedre_irregulier *Forme1= new Polyedre_irregulier(*P1,4,list_sommets1);
    Polyedre_irregulier *Forme2= new Polyedre_irregulier(*P2,4,list_sommets2);
    Fond.push_back(Forme1);
    Fond.push_back(Forme2);
    page->creer_fond(Fond);
    return(page);
}

Page *Page3(){
    Page *page= new Page();
    //boutons
    Bouton *Reguliere = new Bouton(45, 15, 30, 30, "régulière");
    *page += Reguliere;
    Bouton *Irreguliere = new Bouton(45, 60, 30, 30, "irrégulière");
    *page += Irreguliere;
    Bouton *sommetplus = new Bouton(45, 120, 30, 30, "+");
    *page += sommetplus;
    Bouton *sommetmoins = new Bouton(90, 120, 30, 30, "-");
    *page += sommetmoins;
    Texte *sommet_temp= new Texte(15,120,12,0xFF0000FF,"0");
    *page += sommet_temp;
    Texte *sommet= new Texte(105,120,12,0xFF0000FF,"nombre de sommets");
    *page += sommet;

    Bouton *xplus = new Bouton(400, 120, 30, 30, "x +");
    *page += xplus;
    Bouton *xmoins = new Bouton(445, 120, 30, 30, "x -");
    *page += xmoins;
    Texte *x_temp= new Texte(375,120,12,0xFF0000FF,"0");
    *page += x_temp;
    Bouton *yplus = new Bouton(400, 165, 30, 30, "y +");
    *page += yplus;
    Bouton *ymoins = new Bouton(445, 165, 30, 30, "y -");
    *page += ymoins;
    Texte *y_temp= new Texte(375,165,12,0xFF0000FF,"0");
    *page += y_temp;
    std::vector <Polyedre_irregulier *> Fond;
    Point *P1=new Point(480,135);
    Point *P2=new Point(240,405);
    std::vector<Point > list_sommets1;
    std::vector<Point > list_sommets2;
    //list_sommets1.push_back();
    //list_sommets2.push_back();
    Polyedre_irregulier *Forme1= new Polyedre_irregulier(*P1,4,list_sommets1);
    Polyedre_irregulier *Forme2= new Polyedre_irregulier(*P2,4,list_sommets2);
    Fond.push_back(Forme1);
    Fond.push_back(Forme2);
    page->creer_fond(Fond);
    return(page);
}

