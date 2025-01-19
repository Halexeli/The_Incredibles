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
    return(page);
}

Page *Page2(){
    Page *page= new Page();
    //boutons
    Bouton *Reguliere = new Bouton(145, 15, 120, 30, "reguliere");
    *page += Reguliere; //0
    Bouton *Irreguliere = new Bouton(145, 60, 120, 30, "irreguliere");
    *page += Irreguliere;

    Bouton *sommetplus = new Bouton(145, 150, 30, 30, "+");
    *page += sommetplus;
    Bouton *sommetmoins = new Bouton(290, 150, 30, 30, "-");
    *page += sommetmoins; //3
    Texte *sommet_temp= new Texte(15,150,12,0x1A1A77FF,"4");
    *page += sommet_temp;//0
    Texte *sommet= new Texte(180,160,12,0x1A1A77FF,"nombre de sommets");
    *page += sommet;//1

    Bouton *xplus = new Bouton(110, 225, 30, 30, "x +");
    *page += xplus; 
    Bouton *xmoins = new Bouton(65, 225, 30, 30, "x -");
    *page += xmoins;
    Texte *x_temp= new Texte(15,235,12,0x1A1A77FF,"400");
    *page += x_temp;//2
    Bouton *yplus = new Bouton(295, 225, 30, 30, "y +");
    *page += yplus;//6
    Bouton *ymoins = new Bouton(250, 225, 30, 30, "y -");
    *page += ymoins;
    Texte *y_temp= new Texte(200,235,12,0x1A1A77FF,"300");
    *page += y_temp;//3

    Bouton *tailleplus = new Bouton(145, 300, 30, 30, "+");
    *page += tailleplus;
    Bouton *taillemoins = new Bouton(290, 300, 30, 30, "-");
    *page += taillemoins;//9
    Texte *taille_temp= new Texte(15,300,12,0x1A1A77FF,"100");
    *page += taille_temp;//4
    Texte *taille= new Texte(180,310,12,0x1A1A77FF,"taille de la figure");
    *page += taille;//5

    Bouton *crayonplus = new Bouton(145, 375, 30, 30, "+");
    *page += crayonplus;
    Bouton *crayonmoins = new Bouton(290, 375, 30, 30, "-");
    *page += crayonmoins;
    Texte *crayon_temp= new Texte(15,375,12,0x1A1A77FF,"0.3");
    *page += crayon_temp;//6
    Texte *crayon= new Texte(180,375,12,0x1A1A77FF,"taille du crayon");
    *page += crayon;//7

    Bouton *ok= new Bouton(845, 15, 30, 30, "OK");
    *page += ok;//12
    //Texte *TypeFigure=new Texte(500,15,12,0x1A1A77FF,"Figure reguliere");
    //*page += TypeFigure;//8


    Bouton *speedPlus = new Bouton(145, 450, 30, 30, "+");
    *page += speedPlus;
    Bouton *speedMinus = new Bouton(290, 450, 30, 30, "-");
    *page += speedMinus;
    Texte *speedLabel = new Texte(180, 460, 12, 0x1A1A77FF, "Speed");
    *page += speedLabel;
    return(page);
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

    Bouton *xplus = new Bouton(110, 225, 30, 30, "x +");
    *page += xplus; 
    Bouton *xmoins = new Bouton(65, 225, 30, 30, "x -");
    *page += xmoins;
    Texte *x_temp= new Texte(15,235,12,0x1A1A77FF,"400");
    *page += x_temp;//2
    Bouton *yplus = new Bouton(295, 225, 30, 30, "y +");
    *page += yplus;//6
    Bouton *ymoins = new Bouton(250, 225, 30, 30, "y -");
    *page += ymoins;
    Texte *y_temp= new Texte(200,235,12,0x1A1A77FF,"300");
    *page += y_temp;//3

    Bouton *tailleplus = new Bouton(145, 300, 30, 30, "+");
    *page += tailleplus;
    Bouton *taillemoins = new Bouton(290, 300, 30, 30, "-");
    *page += taillemoins;
    Texte *taille_temp= new Texte(15,300,12,0x1A1A77FF,"0");
    *page += taille_temp;
    Texte *taille= new Texte(180,300,12,0x1A1A77FF,"rayon du sommet\npar rapport au 'centre'");
    *page += taille;

    Bouton *crayonplus = new Bouton(145, 375, 30, 30, "+");
    *page += crayonplus;
    Bouton *crayonmoins = new Bouton(290, 375, 30, 30, "-");
    *page += crayonmoins;
    Texte *crayon_temp= new Texte(15,375,12,0x1A1A77FF,"0.3");
    *page += crayon_temp;//6
    Texte *crayon= new Texte(180,375,12,0x1A1A77FF,"taille du crayon");
    *page += crayon;//7

    Bouton *oksommet= new Bouton(445, 490, 30, 30, "OK");
    *page += oksommet;
    Texte *Nbsommet=new Texte(345,500,12,0x1A1A77FF,"Sommet 1");
    *page += Nbsommet;

    Bouton *ok= new Bouton(845, 15, 30, 30, "OK");
    *page += ok;
    
    //Texte *TypeFigure=new Texte(500,15,12,0x1A1A77FF,"Figure irreguliere");
    //*page += TypeFigure;
    return(page);
}

void del_page(Page *page){
    std::vector <Texte *> Texte=page->get_List_string();
    for(auto it:Texte){
        if(it!=nullptr)
            delete it;
    }
   int i=0;
    std::vector <Bouton *> Bouton=page->get_List_Bouton();
    for(auto it:Bouton){
        delete it;
        i++;
    } 
    delete page;
}