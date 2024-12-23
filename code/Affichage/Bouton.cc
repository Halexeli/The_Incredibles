#include "Bouton.hh"
#include "SFML/Window.hpp"

bool Bouton::Ispressed(Screen &screen){
    return(screen.Buttonclicked(x,y,w,h));
}

void Bouton::draw(Screen &screen){
    screen.rect(x,y,w,h,0x0A0A0A);
    if(signe)
    screen.text(x,y,"+",h*3/4,0x000000,font_file);
    if(!signe)
    screen.text(x,y,"-",h*3/4,0x000000,font_file);
}

void Texte::draw(Screen &screen){
    screen.text(x,y,texte,taille,color,font_file);
}