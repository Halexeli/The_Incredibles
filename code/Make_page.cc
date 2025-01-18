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
    Bouton *Clear=new Bouton(860, 495, 60, 30, "Clear");
    *page += Clear;
    return(page);
}

Page *Page2(){
    Page *page= new Page();
    //boutons
    /*
    Bouton *Reguliere = new Bouton(145, 15, 120, 30, "reguliere");
    *page += Reguliere; //0
    Bouton *Irreguliere = new Bouton(145, 60, 120, 30, "irreguliere");
    *page += Irreguliere;
*/
    Bouton *sommetmoins = new Bouton(145, 60, 30, 30, "-");
    *page += sommetmoins;//0
    Bouton *sommetplus = new Bouton(290, 60, 30, 30, "+");
    *page += sommetplus; //1
    Texte *sommet_temp= new Texte(15,65,18,0xA3D5FFFF,"5");
    *page += sommet_temp;//0
    Texte *sommet= new Texte(180,70,12,0xA3D5FFFF,"nombre de sommets");
    *page += sommet;//1

    Bouton *xplus = new Bouton(605, 60, 30, 30, "x +");
    *page += xplus; //2
    Bouton *xmoins = new Bouton(560, 60, 30, 30, "x -");
    *page += xmoins;//3
    Texte *x_temp= new Texte(495,70,12,0xA3D5FFFF,"400");
    *page += x_temp;//2
    Bouton *yplus = new Bouton(790, 60, 30, 30, "y +");
    *page += yplus;//4
    Bouton *ymoins = new Bouton(745, 60, 30, 30, "y -");
    *page += ymoins;//5
    Texte *y_temp= new Texte(680,70,12,0xA3D5FFFF,"300");
    *page += y_temp;//3

    Bouton *tailleplus = new Bouton(290, 105, 30, 30, "+");
    *page += tailleplus;//6
    Bouton *taillemoins = new Bouton(145, 105, 30, 30, "-");
    *page += taillemoins;//7
    Texte *taille_temp= new Texte(15,110,18,0xA3D5FFFF,"100");
    *page += taille_temp;//4
    Texte *taille= new Texte(180,115,12,0xA3D5FFFF,"taille de la figure");
    *page += taille;//5

    Bouton *crayonplus = new Bouton(770, 105, 30, 30, "+");
    *page += crayonplus;//8
    Bouton *crayonmoins = new Bouton(625, 105, 30, 30, "-");
    *page += crayonmoins;//9
    Texte *crayon_temp= new Texte(495,110,18,0xA3D5FFFF,"0.3");
    *page += crayon_temp;//6
    Texte *crayon= new Texte(660,115,12,0xA3D5FFFF,"taille du crayon");
    *page += crayon;//7

    Bouton *ok= new Bouton(845, 15, 30, 30, "OK");
    *page += ok;//10
    Texte *TypeFigure=new Texte(500,15,12,0xA3D5FFFF,"Figure reguliere");
    *page += TypeFigure;//8

    Bouton *rose= new Bouton(15, 165, 75, 30, "Rose",0xFF33D4FF);
    *page+=rose;
    Bouton *Violet= new Bouton(15, 210, 75, 30, "Violet",0xA41BFDFF);
    *page+=Violet;
    Bouton *bleu= new Bouton(15, 255, 75, 30, "Bleu",0x0785FCFF);
    *page+=bleu;
    Bouton *Vert= new Bouton(15, 300, 75, 30, "Vert",0x00FF00FF);
    *page+=Vert;
    Bouton *Jaune= new Bouton(15, 345, 75, 30, "Jaune",0xFEFC1DFF);
    *page+=Jaune;
    Bouton *Orange= new Bouton(15, 390, 75, 30, "Orange",0xF76C1AFF);
    *page+=Orange;
    Bouton *Rouge= new Bouton(15, 435, 75, 30, "Rouge",0xF90B08FF);
    *page+=Rouge;
    return(page);
}
/*
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
    Texte *TypeFigure=new Texte(500,15,12,0x1A1A77FF,"Figure irreguliere");
    *page += TypeFigure;
    return(page);
}
*/
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