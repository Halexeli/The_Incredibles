#include "Bouton.hh"
#include "SFML/Window.hpp"

bool Bouton::Ispressed(Screen &screen){
    return(screen.Buttonclicked(x,y,w,h));
}

void Bouton::draw(Screen &screen) {
    screen.rect(x, y, w, h, 0x1A1A77FF); //RGB
    if (!label.empty()) {
        screen.draw(text);
    }
}

void Texte::draw(Screen &screen){
    screen.text(x,y,texte,taille,color,font_file);
}