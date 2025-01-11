#include <SFML/Graphics.hpp>
#include "Affichage/Page.hh"  
#include "Affichage/Screen.hh"
#include "Spirographe/Spirographe.hh"
#include "Affichage/Bouton.hh"

Page *Page1(){
    Page *page= new Page();
    //boutons
    Bouton *NouvelleFigure = new Bouton(15, 15, 120, 30, "Nouvelle Figure");
    *page += NouvelleFigure;
    std::vector <Polyedre_irregulier *> Fond;
    Point *P1=new Point(480,50);
    Point *P2=new Point(-480,-50);
    Point *P3=new Point(-480,50);
    Point *P4=new Point(480,50);
    Point *P5=new Point(480,-50);
    std::vector<Point *> list_sommets;
    list_sommets.push_back(P2);
    list_sommets.push_back(P3);
    list_sommets.push_back(P4);
    list_sommets.push_back(P5);
    Polyedre_irregulier *Forme1= new Polyedre_irregulier(P1,4,list_sommets);
    Fond.push_back(Forme1);
    page->creer_fond(Fond);
    return(page);
}

Page *Page2(){
    Page *page= new Page();
    //boutons
    Bouton *Reguliere = new Bouton(145, 15, 120, 30, "reguliere");
    *page += Reguliere;
    Bouton *Irreguliere = new Bouton(145, 60, 120, 30, "irreguliere");
    *page += Irreguliere;

    Bouton *sommetplus = new Bouton(145, 150, 30, 30, "+");
    *page += sommetplus;
    Bouton *sommetmoins = new Bouton(290, 150, 30, 30, "-");
    *page += sommetmoins;
    Texte *sommet_temp= new Texte(15,150,12,0x1A1A77FF,"0");
    *page += sommet_temp;
    Texte *sommet= new Texte(180,160,12,0x1A1A77FF,"nombre de sommets");
    *page += sommet;

    Bouton *xplus = new Bouton(65, 225, 30, 30, "x +");
    *page += xplus;
    Bouton *xmoins = new Bouton(110, 225, 30, 30, "x -");
    *page += xmoins;
    Texte *x_temp= new Texte(15,235,12,0x1A1A77FF,"0");
    *page += x_temp;
    Bouton *yplus = new Bouton(250, 225, 30, 30, "y +");
    *page += yplus;
    Bouton *ymoins = new Bouton(295, 225, 30, 30, "y -");
    *page += ymoins;
    Texte *y_temp= new Texte(200,235,12,0x1A1A77FF,"0");
    *page += y_temp;

    Bouton *tailleplus = new Bouton(145, 300, 30, 30, "+");
    *page += tailleplus;
    Bouton *taillemoins = new Bouton(290, 300, 30, 30, "-");
    *page += taillemoins;
    Texte *taille_temp= new Texte(15,300,12,0x1A1A77FF,"0");
    *page += taille_temp;
    Texte *taille= new Texte(180,310,12,0x1A1A77FF,"taille de la figure");
    *page += taille;

    Bouton *angleplus = new Bouton(145, 375, 30, 30, "+");
    *page += angleplus;
    Bouton *anglemoins = new Bouton(290, 375, 30, 30, "-");
    *page += anglemoins;
    Texte *angle_temp= new Texte(15,375,12,0x1A1A77FF,"0");
    *page += angle_temp;
    Texte *angle= new Texte(180,375,12,0x1A1A77FF,"angle de la figure\npar rapport a l'axe x");
    *page += angle;

    Bouton *ok= new Bouton(845, 15, 30, 30, "OK");
    *page += ok;
    Texte *TypeFigure=new Texte(500,15,12,0x1A1A77FF,"Figure reguliere");
    *page += TypeFigure;
    std::vector <Polyedre_irregulier *> Fond;
    Point *P1=new Point(480,135);
    Point *p11=new Point(-480,-135);
    Point *p12=new Point(480,-135);
    Point *p13=new Point(480,135);
    Point *p14=new Point(-480,135);
    Point *P2=new Point(240,405);
    Point *p21=new Point(-240,-135);
    Point *p22=new Point(240,-135);
    Point *p23=new Point(240,135);
    Point *p24=new Point(-240,135);
    std::vector<Point *> list_sommets1;
    std::vector<Point*> list_sommets2;
    list_sommets1.push_back(p11);
    list_sommets1.push_back(p12);
    list_sommets1.push_back(p13);
    list_sommets1.push_back(p14);
    list_sommets2.push_back(p21);
    list_sommets2.push_back(p22);
    list_sommets2.push_back(p23);
    list_sommets2.push_back(p24);
    Polyedre_irregulier *Forme1= new Polyedre_irregulier(P1,4,list_sommets1);
    Polyedre_irregulier *Forme2= new Polyedre_irregulier(P2,4,list_sommets2);
    Fond.push_back(Forme1);
    Fond.push_back(Forme2);
    page->creer_fond(Fond);
    return(page);
}

void del_page(Page *page){
    std::vector<Polyedre_irregulier *> Formes_irr=page->get_Formes_irr();
    for(auto it:Formes_irr){
        std::vector <Point *> sommets=it->getList();
        for(auto it2:sommets){
            delete it2;
        }
        delete it->getCentre();
        delete it;
    } 
    std::vector<Polyedre_regulier *> Formes_r=page->get_Formes_r();
    for(auto it:Formes_r){
        delete it->getCentre();
        delete it;
    } 
    std::vector <Spirographe *> Spiro=page->get_Spiro();
    for(auto it:Spiro){
        delete it;
    } 
    std::vector <Bouton *> Bouton=page->get_List_Bouton();
    for(auto it:Bouton){
        delete it;
    } 
    std::vector <Polyedre_irregulier *> Fond=page->get_Fond();
    for(auto it:Fond){
        std::vector <Point *> sommets=it->getList();
        for(auto it2:sommets){
            delete it2;
        }
        delete it->getCentre();
        delete it;
    }
    std::vector <Texte *> Texte=page->get_List_string();
    for(auto it:Texte){
        delete it;
    }
    delete page;
}

Page *Page3(){
    Page *page= new Page();
    //boutons
    Bouton *Reguliere = new Bouton(145, 15, 120, 30, "reguliere");
    *page += Reguliere;
    Bouton *Irreguliere = new Bouton(145, 60, 120, 30, "irreguliere");
    *page += Irreguliere;

    Bouton *sommetplus = new Bouton(145, 150, 30, 30, "+");
    *page += sommetplus;
    Bouton *sommetmoins = new Bouton(290, 150, 30, 30, "-");
    *page += sommetmoins;
    Texte *sommet_temp= new Texte(15,150,12,0x1A1A77FF,"0");
    *page += sommet_temp;
    Texte *sommet= new Texte(180,160,12,0x1A1A77FF,"nombre de sommets");
    *page += sommet;

    Bouton *xplus = new Bouton(65, 225, 30, 30, "x +");
    *page += xplus;
    Bouton *xmoins = new Bouton(110, 225, 30, 30, "x -");
    *page += xmoins;
    Texte *x_temp= new Texte(15,235,12,0x1A1A77FF,"0");
    *page += x_temp;
    Bouton *yplus = new Bouton(250, 225, 30, 30, "y +");
    *page += yplus;
    Bouton *ymoins = new Bouton(295, 225, 30, 30, "y -");
    *page += ymoins;
    Texte *y_temp= new Texte(200,235,12,0x1A1A77FF,"0");
    *page += y_temp;

    Bouton *tailleplus = new Bouton(145, 300, 30, 30, "+");
    *page += tailleplus;
    Bouton *taillemoins = new Bouton(290, 300, 30, 30, "-");
    *page += taillemoins;
    Texte *taille_temp= new Texte(15,300,12,0x1A1A77FF,"0");
    *page += taille_temp;
    Texte *taille= new Texte(180,300,12,0x1A1A77FF,"rayon du sommet\npar rapport au 'centre'");
    *page += taille;

    Bouton *angleplus = new Bouton(145, 375, 30, 30, "+");
    *page += angleplus;
    Bouton *anglemoins = new Bouton(290, 375, 30, 30, "-");
    *page += anglemoins;
    Texte *angle_temp= new Texte(15,375,12,0x1A1A77FF,"0");
    *page += angle_temp;
    Texte *angle= new Texte(180,375,12,0x1A1A77FF,"angle de la figure\npar rapport a l'axe x");
    *page += angle;

    Bouton *oksommet= new Bouton(445, 490, 30, 30, "OK");
    *page += oksommet;
    Texte *Nbsommet=new Texte(345,500,12,0x1A1A77FF,"Sommet 1");
    *page += Nbsommet;

    Bouton *ok= new Bouton(845, 15, 30, 30, "OK");
    *page += ok;
    Texte *TypeFigure=new Texte(500,15,12,0x1A1A77FF,"Figure irreguliere");
    *page += TypeFigure;
    std::vector <Polyedre_irregulier *> Fond;
    Point *P1=new Point(480,135);
    Point *p11=new Point(-480,-135);
    Point *p12=new Point(480,-135);
    Point *p13=new Point(480,135);
    Point *p14=new Point(-480,135);
    Point *P2=new Point(240,405);
    Point *p21=new Point(-240,-135);
    Point *p22=new Point(240,-135);
    Point *p23=new Point(240,135);
    Point *p24=new Point(-240,135);
    std::vector<Point *> list_sommets1;
    std::vector<Point*> list_sommets2;
    list_sommets1.push_back(p11);
    list_sommets1.push_back(p12);
    list_sommets1.push_back(p13);
    list_sommets1.push_back(p14);
    list_sommets2.push_back(p21);
    list_sommets2.push_back(p22);
    list_sommets2.push_back(p23);
    list_sommets2.push_back(p24);
    Polyedre_irregulier *Forme1= new Polyedre_irregulier(P1,4,list_sommets1);
    Polyedre_irregulier *Forme2= new Polyedre_irregulier(P2,4,list_sommets2);
    Fond.push_back(Forme1);
    Fond.push_back(Forme2);
    page->creer_fond(Fond);
    return(page);
}

